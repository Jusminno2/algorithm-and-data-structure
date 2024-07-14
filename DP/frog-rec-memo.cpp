#include <iostream>
#include <vector>
using namespace std;

// aがbより大きければ、aをbに更新する
template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

const long long INF = 1LL << 60;

// 入力データと、メモ用のDPテーブル
int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i) {
  // dP の値が更新されていたらそのままリターン
  // dp が INF ではなくなっているということは、dpが更新されているということ
  if (dp[i] < INF) return dp[i];

  // basecase
  if (i == 0) return 0;

  // 答えを表す変数を INF で初期化する
  long long res = INF;

  // 足場 i-1 から来た場合
  // 緩和関数により更新が行われる
  chmin(res, rec(i-1) + abs(h[i] - h[i-1]));

  // 足場 i-2 から来た場合
  if (i > 1) chmin(res, rec(i-2) + abs(h[i] - h[i-2]));

  // 結果をメモ化しながら返す
  return dp[i] = res;
}

int main() {
  // 入力受取
  cin >> N;
  // resize => 配列の要素数をNとする
  h.resize(N);
  for (int i = 0; i < N; i++) cin >> h[i];

  // 初期化（最小問題なので INF に初期化）
  dp.assign(N, INF);

  // 答え
  cout << rec(N-1) << endl;
}