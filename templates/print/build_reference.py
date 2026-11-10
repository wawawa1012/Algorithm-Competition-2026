from pathlib import Path
import html
import json
import re
from reportlab.pdfgen import canvas
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.pagesizes import A4

OUT = Path(__file__).resolve().parent
pdfmetrics.registerFont(TTFont('CN', r'C:\Windows\Fonts\simhei.ttf'))
pdfmetrics.registerFont(TTFont('Code', r'C:\Windows\Fonts\consola.ttf'))

def h(t): return ('h', t)
def p(t): return ('p', t)
def c(t): return ('c', t.strip('\n'))

PAGES = [
('程序 数值 容器 字符串', [
 [h('完整程序与读入输出'),
  p('C++17。片段中 a 默认从 0 开始，n 为元素个数；按题意补输入、初值和合法性判断。'),
  c('''#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    ll answer = 0; // compute the real answer
    cout << answer << '\\n';
    return 0;
}'''),
  p('answer 换成你算出的答案变量。每个输入一般只处理一组；只有题面给 T 时才循环 T 组。输出不加提示文字。'),
  h('先估范围 再选类型'),
  p('int 上限 2147483647；long long 上限约 9.22×10^18。20 万个 10^9 的总和可达 2×10^14。'),
  c('''ll sum = 0;
ll product = 1LL * x * y;
ll square = 1LL * x * x;
ll best = max(0LL, 1LL * a[0]);
const ll INF = (1LL << 60);'''),
  p('乘法必须先提升运算类型；long long 接收一个已经溢出的 int 结果，救不回来。max 的两个实参类型应一致。INF 要覆盖范围，别对无效哨兵直接做加法。'),
  h('取模与完整大整数'),
  c('''ll MOD = 1000000007;
ll r = ((x % MOD) + MOD) % MOD;
ll add = (u % MOD + v % MOD) % MOD;'''),
  p('以上模数下两项相加安全；递推每一步取模。乘积仍须估范围，不能因最后取模就忽略中间溢出。需要完整超长整数时用 string 逐位运算，stoi/stoll 也有范围。')],
 [h('vector 的大小与下标'),
  c('''vector<int> a(n, 0);
vector<ll> pre(n + 1, 0);
vector<vector<int>> vis(
    H, vector<int>(W, 0));
a.push_back(x);
int last = a.back();
a.pop_back();
int n = (int)a.size();'''),
  p('长度为 n 的数组合法下标是 0 到 n-1。先读 H/W，再分配网格；变量变大不会让旧 vector 自动扩容。reserve 只预留空间，不能代替 resize。back/pop_back 前保证非空。'),
  c('''for (int& x : a) cin >> x;
for (const auto& x : a) {
    cout << x << ' ';
}
// 1-based storage
vector<int> b(n + 1);
for (int i = 1; i <= n; ++i)
    cin >> b[i];'''),
  p('用 1 起点就多开一格；用 0 起点就单独检查 n=1 时是否访问了下标 1。'),
  h('pair 与结构化绑定'),
  c('''#include <utility>
pair<int, int> pt = {2, 7};
cout << pt.first << ' ' << pt.second;
auto [x, y] = pt;
vector<pair<int, ll>> events;'''),
  p('改过 pair 的结构后，逐处核对 first/second 的含义。'),
  h('string 常用操作'),
  c('''string s, t;
cin >> s >> t;
int n = (int)s.size();
char ch = s[i];
int digit = s[i] - '0';
int ascii = (unsigned char)s[i];
string number = to_string(123);
string sub = s.substr(l, r - l + 1);
s += t;
reverse(s.begin(), s.end());
bool less = (s < t);'''),
  p('substr 第一个参数是 0 起点，第二个是长度。字符串比较按字典序，不按数值大小。字符数字转值用减 \'0\'；字母转 ASCII 数字串用 to_string(int(ch))。'),
  c('''getline(cin >> ws, s);'''),
  p('这一写法跳过前导空白再读整行。若前导空格本身有意义，应只清理前一行剩余换行后再 getline。')]
]),
('排序 二分 哈希 栈 队列 堆', [
 [h('排序与比较函数'),
  c('''sort(a.begin(), a.end());
sort(a.begin(), a.end(), greater<int>());
sort(v.begin(), v.end(),
     [](const auto& x, const auto& y) {
         return x.second < y.second;
     });'''),
  p('pair 默认先比 first，再比 second。比较函数用严格关系 < 或 >，不要写 <=。排序会改变原顺序，需要位置时一起保存原下标。'),
  h('有序数组上的二分接口'),
  c('''auto lo = lower_bound(
    a.begin(), a.end(), x);
auto hi = upper_bound(
    a.begin(), a.end(), x);
int first = (int)(lo - a.begin());
int count = (int)(hi - lo);
bool found = lo != a.end() && *lo == x;'''),
  p('前提：a 按升序排列。lower_bound 找第一个 >=x；upper_bound 找第一个 >x。没找到位置可能是 n，end() 不能解引用。'),
  h('哈希计数与首次位置'),
  c('''#include <unordered_map>
unordered_map<int, int> freq;
for (int x : a) ++freq[x];
auto it = freq.find(x);
int cnt = (it == freq.end()
           ? 0 : it->second);

unordered_map<int, int> firstPos;
for (int i = 0; i < n; ++i) {
    if (!firstPos.count(a[i]))
        firstPos[a[i]] = i;
}'''),
  p('键是查询值，值是次数/位置等信息。预处理只建一次；不能每次询问重扫数组。mp[x] 在键不存在时会插入默认值；只查询可用 find。哈希平均 O(1)，最坏不保证。'),
  h('复杂度快速估算'),
  p('顺序做两遍 n：O(n)，不是 O(n^2)。两层各跑 n：O(n^2)。n×3 的状态仍是线性规模。n=20 万时，通常要避免枚举全部二元配对。')],
 [h('堆与动态最值'),
  c('''priority_queue<int> big;
priority_queue<int, vector<int>,
               greater<int>> small;
priority_queue<ll> pq(
    a.begin(), a.end());
pq.push(x);
if (!pq.empty()) {
    ll value = pq.top();
    pq.pop();
}'''),
  p('默认大根堆，top 是最大值；greater 是小根堆，top 是最小值。top 查看，pop 删除且不返回值；两者都要求非空。堆内部没有整体排序。'),
  p('查看 O(1)，push/pop 各 O(log n)。范围构造整体建堆 O(n)；逐个 push 最坏 O(n log n)。后续反复修改仍有对数成本。'),
  p('保留最大的 K 项：小根堆；新项入堆后，若超过 K 项就弹最小项。堆顶是保留项中最小者，即第 K 大。最小的 K 项则对称使用大根堆。'),
  p('修改堆顶：先 top 保存、pop 删除，计算新值后 push 回去。合并后数值会变大时，堆元素和中间量都要估范围。'),
  h('栈与队列接口'),
  c('''#include <stack>
stack<int> st;
st.push(x);
if (!st.empty()) {
    int value = st.top();
    st.pop();
}

queue<pair<int, int>> q;
q.push({sx, sy});
if (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
}'''),
  p('栈后进先出，用 top；队列先进先出，用 front。queue.pop() 删除队首，不能拿 back() 当成被删除的元素。括号匹配遇右括号先检查空栈。'),
  h('调试时先看最短输入'),
  p('n=1、K=1、K=N、全相同、全负数、无解、答案为 0。结果错误先核对变量含义、更新顺序和初值，再检查多加/少加了一次。')]
]),
('前缀和 差分 事件 双指针 窗口', [
 [h('前缀和与区间查询'),
  c('''vector<ll> pre(n + 1, 0);
for (int i = 0; i < n; ++i)
    pre[i + 1] = pre[i] + a[i];
// query [l, r], 1-based inclusive
ll sum = pre[r] - pre[l - 1];
// query [l, r], 0-based inclusive
ll sum0 = pre[r + 1] - pre[l];'''),
  p('pre[i] 是前 i 个数的和，pre[0]=0。查询端点的起点体系必须和公式一致。建表一次 O(n)，每次询问 O(1)。累计范围常比单项大。'),
  h('闭区间加法与恢复'),
  c('''vector<ll> diff(n + 2, 0);
// add v to [l,r], 1-based
diff[l] += v;
diff[r + 1] -= v;

ll added = 0;
for (int i = 1; i <= n; ++i) {
    added += diff[i];
    result[i - 1] = a[i - 1] + added;
}'''),
  p('先记录全部区间操作，再累计恢复。added 表示当前位置受到的总增量；若原数组全 0，它就是恢复后的值。闭区间撤销在 r+1，多留一格。若还要问覆盖量的区间总和，对恢复结果再建一次前缀和。'),
  h('稀疏时间事件与分段计费'),
  c('''#include <map>
map<ll, ll> delta;
delta[l] += cost;
delta[r + 1] -= cost;

ll cur = 0, ans = 0;
ll last = delta.begin()->first;
for (auto [t, change] : delta) {
    ans += min(cur, cap) * (t - last);
    cur += change;
    last = t;
}'''),
  p('上例为至少一个服务、闭区间按日收费并设每日上限 cap。先用旧 cur 结算 [last,t)，再更新。时间长度是 t-last，不是事件个数。半开区间 [l,r) 在 r 撤销；同一时刻增量合并后再检查容量。')],
 [h('相向双指针'),
  c('''sort(a.begin(), a.end());
int l = 0, r = n - 1;
while (l < r) {
    ll sum = 1LL * a[l] + a[r];
    if (sum == target) {
        // record the pair
        break;
    }
    if (sum < target) ++l;
    else --r;
}'''),
  p('适用此例的是有序数组中找一对目标和。l<r 保证不复用同一个位置；需要原下标时，排序前保存它。'),
  h('固定长度窗口最大和'),
  c('''ll sum = 0;
for (int i = 0; i < k; ++i)
    sum += a[i];
ll best = sum;
for (int r = k; r < n; ++r) {
    sum += a[r];
    sum -= a[r - k];
    best = max(best, sum);
}'''),
  p('前提 1<=K<=N。必须选满 K 个；全负数组时答案仍为负，不能用 0 初始化最大值。'),
  h('非负数组的至多和计数'),
  c('''ll sum = 0, count = 0;
int l = 0;
for (int r = 0; r < n; ++r) {
    sum += a[r];
    while (l <= r && sum > limit)
        sum -= a[l++];
    count += r - l + 1;
}'''),
  p('前提：a[i]>=0 且 limit>=0。固定 r 后，合法起点为 l..r，所以加 r-l+1，不是 res++。含负数时该单调窗口不能直接套。最长长度类则更新最大 r-l+1。'),
  h('窗口内频次与恰好计数'),
  p('最长无重复段：加入右端使某值频次变成 2，就不断移出左端并扣回频次，直到不重复。左右端移动必须同步更新状态。'),
  p('恰好 K 个奇数：F(K)-F(K-1)，F 表示至多的区间数；F(-1)=0。先数清一个右端点能对应多少起点，不把条件成立次数当区间个数。')]
]),
('基础动态规划 网格搜索 提交检查', [
 [h('先写清状态含义'),
  p('先确定 dp 表示哪一类合法方案，再列最后一步的候选。数组维度由必须保留的信息决定；先算各维乘积，再估时间和空间。最终答案不一定是最后一个状态。'),
  h('不相邻取数 可空选'),
  p('dp[i] 表示前 i 个数的最大总和，dp[0]=0。取当前位置就接前 i-2 个数，否则沿用前 i-1 个数。'),
  c('''vector<ll> dp(n + 1, 0);
for (int i = 1; i <= n; ++i) {
    ll prev = (i >= 2 ? dp[i - 2] : 0);
    dp[i] = max(dp[i - 1],
                prev + a[i - 1]);
}
ll answer = dp[n];'''),
  h('最大连续子数组 非空'),
  p('ending 必须包含当前位置。只能独自开新段，或接在上一位置结尾的段后；跳过负数会破坏连续性。best 记录所有结尾中的最大值。'),
  c('''ll ending = a[0], best = ending;
for (int i = 1; i < n; ++i) {
    ending = max(1LL * a[i],
                 ending + a[i]);
    best = max(best, ending);
}'''),
  h('相邻两天不能选同活动'),
  p('每天 3 项活动，dp[c] 表示截至上一天且上一天选 c 的最大收益。当天选 c 时，只从另外两种旧结尾转移；先算完整 next，再覆盖旧 dp。'),
  c('''#include <array>
array<ll, 3> dp = {
    v[0][0], v[0][1], v[0][2]};
for (int i = 1; i < n; ++i) {
    array<ll, 3> next;
    for (int c = 0; c < 3; ++c)
        next[c] = v[i][c] + max(
            dp[(c + 1) % 3],
            dp[(c + 2) % 3]);
    dp = next;
}
ll answer = max({dp[0], dp[1], dp[2]});'''),
  h('分类候选何时能压缩'),
  p('固定右端点后，若所有同类旧候选都只差一个固定加数，只需保留该类最大候选值。先明确哪些旧位置已经合法，再加入；必须保留历史最大，不能直接覆盖。不要因为看见颜色就机械开 n×k 状态。')],
 [h('BFS 无权图最短步数'),
  p('grid[x][y] 中 x 是行，y 是列，# 是墙。读完 H/W 后分配 dist。起点可走，四个方向每步代价均为 1。'),
  c('''int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<int>> dist(
    H, vector<int>(W, -1));
queue<pair<int,int>> q;
dist[sx][sy] = 0;
q.push({sx,sy});
while (!q.empty()) {
    auto [x,y] = q.front(); q.pop();
    for (int d = 0; d < 4; ++d) {
        int nx=x+dx[d], ny=y+dy[d];
        if (nx<0 || nx>=H ||
            ny<0 || ny>=W) continue;
        if (grid[nx][ny]=='#' ||
            dist[nx][ny]!=-1) continue;
        dist[nx][ny]=dist[x][y]+1;
        q.push({nx,ny});
    }
}'''),
  p('入队时就标记，避免重复入队。终点 dist=-1 表示不可达。BFS 的这份实现用队列循环，不是递归。'),
  h('DFS 的调用与返回'),
  p('一层负责当前格：先标记，再逐个递归访问合法邻格。子调用结束后，回到调用后的下一句，继续本层循环。连通块计数中 visited 通常不撤销；枚举路径的回溯才按状态需要撤销。'),
  p('大网格可能递归过深。只求可达或连通块时，也可用队列/显式栈遍历；普通 DFS 第一次找到终点的路径不保证最短。'),
  h('提交前最后检查'),
  p('① main 有读入和输出，函数确实被调用；所有非 void 路径有 return。② 单元素、全负、全相同、无解和最大数值。③ 下标 0/1 起点及 r+1 的容量。④ 队列 front 与 pop 对应。⑤ 累计量和中间乘积的类型。'),
  h('赛前与赛场'),
  p('关闭 IDE 自动补全、整行建议和模板展开。纸质资料可查；不要把开卷理解成可搜索网页。先扫题，优先做能明确写出步骤的题；卡住先留草稿，再换题。'),
  p('规则来源：组委会 2026-11-10 指南 50362；赛事主页 11-06 回复允许纸质资料。'),
  p('m.saikr.com/contest/notice_detail/50362\nm.saikr.com/adpc2026autumn')]
])]

WIDTH, HEIGHT = A4
MARGIN = 34
GAP = 20
COL = (WIDTH - 2 * MARGIN - GAP) / 2

def wrap(text, font, size, width):
    lines = []
    for raw in text.split('\n'):
        if not raw:
            lines.append('')
            continue
        current = ''
        tokens = list(raw) if font == 'Code' else re.findall(r'[!-~×]+|.', raw)
        for ch in tokens:
            if current and pdfmetrics.stringWidth(current + ch, font, size) > width:
                if ch in '，。；：？！、）】' and len(current) > 1:
                    tail = re.search(r'[!-~×]+$', current)
                    cut = tail.start() if tail else len(current) - 1
                    if cut == 0:
                        lines.append(current + ch)
                        current = ''
                    else:
                        lines.append(current[:cut])
                        current = current[cut:] + ch
                else:
                    lines.append(current)
                    current = ch
            else:
                current += ch
        lines.append(current)
    return lines

def build():
    target = OUT / 'cpp-contest-reference.pdf'
    cv = canvas.Canvas(str(target), pagesize=A4)
    cv.setTitle('竞赛编程速查表')
    cv.setAuthor('Algorithm Competition Training')
    stats = []
    for page_no, (label, columns) in enumerate(PAGES, 1):
        cv.setFillColorRGB(0, 0, 0)
        cv.setFont('CN', 18 if page_no == 1 else 15)
        title = '竞赛编程速查表' if page_no == 1 else '竞赛编程速查表 ' + str(page_no)
        cv.drawString(MARGIN, HEIGHT - 38, title)
        cv.setFont('CN', 9.6)
        cv.drawString(MARGIN, HEIGHT - 56, label)
        for column_no, blocks in enumerate(columns):
            x = MARGIN + column_no * (COL + GAP)
            y = HEIGHT - 80
            for kind, text in blocks:
                if kind == 'h':
                    font, size, leading, before, after = 'CN', 12, 17, 5, 3
                elif kind == 'c':
                    font, size, leading, before, after = 'Code', 9.3, 11.8, 1, 4
                else:
                    font, size, leading, before, after = 'CN', 10.2, 13.8, 0, 4
                y -= before
                cv.setFont(font, size)
                for line in wrap(text, font, size, COL):
                    cv.drawString(x, y, line)
                    y -= leading
                y -= after
            stats.append({'page': page_no, 'column': column_no + 1, 'bottom': round(y, 1)})
            if y < 41:
                raise RuntimeError(f'Column overflow: page {page_no}, column {column_no+1}, bottom={y:.1f}')
        cv.setFont('CN', 8.3)
        cv.drawString(MARGIN, 23, 'C++17  常用语法与已练模型  2026年11月10日')
        cv.drawRightString(WIDTH - MARGIN, 23, f'{page_no} / 4')
        cv.showPage()
    cv.save()

    chunks = ['''<!doctype html><html lang="zh-CN"><meta charset="utf-8">
<title>竞赛编程速查表</title><style>
@page{size:A4;margin:12mm}*{box-sizing:border-box}body{margin:0;color:#000;font-family:SimHei,"Microsoft YaHei",sans-serif}
.page{page-break-after:always;max-width:186mm;margin:0 auto;padding:0 0 5mm}.page:last-child{page-break-after:auto}
h1{font-size:18pt;margin:0 0 3mm;font-weight:normal}.subtitle{font-size:10pt;margin:0 0 5mm}
.cols{display:grid;grid-template-columns:1fr 1fr;column-gap:7mm}h2{font-size:12pt;margin:3mm 0 1.5mm}
p{font-size:10.2pt;line-height:1.35;margin:0 0 1.5mm;white-space:pre-wrap}pre{font-family:Consolas,monospace;font-size:9.3pt;line-height:1.27;margin:0 0 2mm;white-space:pre-wrap;overflow-wrap:anywhere}
footer{font-size:8pt;margin-top:3mm}@media screen{body{background:#ddd}.page{background:white;padding:12mm;max-width:210mm;margin:8mm auto}}
</style><body>''']
    for i, (label, columns) in enumerate(PAGES, 1):
        chunks.append(f'<section class="page"><h1>竞赛编程速查表 {i}</h1><div class="subtitle">{html.escape(label)}</div><div class="cols">')
        for blocks in columns:
            chunks.append('<div>')
            for kind, text in blocks:
                tag = {'h': 'h2', 'p': 'p', 'c': 'pre'}[kind]
                chunks.append(f'<{tag}>{html.escape(text)}</{tag}>')
            chunks.append('</div>')
        chunks.append(f'</div><footer>C++17　2026年11月10日　{i} / 4</footer></section>')
    chunks.append('</body></html>')
    (OUT / 'cpp-contest-reference.html').write_text('\n'.join(chunks), encoding='utf-8')
    (OUT / 'reference-content.json').write_text(json.dumps(PAGES, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps({'pdf': str(target), 'columns': stats}, ensure_ascii=False))

if __name__ == '__main__':
    build()
