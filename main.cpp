#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

struct Rect {
  ll t;
  ll b;
  ll l;
  ll r;
};
using vR = vector<Rect>;

ll w, h;
ll m;
vR rects;

ll CalcArea(const Rect& rect) {
  const auto& w = rect.r - rect.l;
  const auto& h = rect.b - rect.t;
  const auto& area = w * h;

  return area;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> w >> h;
  cin >> m;
  rects.push_back({0, h, 0, w});
  while (0 < (m--)) {
    ll d, v;
    cin >> d >> v;

    auto tp = vR{};
    tp.reserve(rects.size() * 2);

    for (const auto& rect : rects) {
      if (0 == d) {
        if (rect.t < v && v < rect.b) {
          tp.push_back(Rect{rect.t, v, rect.l, rect.r});
          tp.push_back(Rect{v, rect.b, rect.l, rect.r});
        } else {
          tp.push_back(rect);
        }
      } else if (1 == d) {
        if (rect.l < v && v < rect.r) {
          tp.push_back(Rect{rect.t, rect.b, rect.l, v});
          tp.push_back(Rect{rect.t, rect.b, v, rect.r});
        } else {
          tp.push_back(rect);
        }
      }
    }

    rects = vR(tp);
  }

  sort(rects.begin(), rects.end(),
       [](const Rect& a, const Rect& b) { return CalcArea(b) < CalcArea(a); });

  cout << CalcArea(rects[0]);

  return 0;
}