//Name: Pizza
//Level: 3
//Category: 二分探索,環状,練習問題
//Note:

/**
 * 家kから一番近い店舗は、時計回りに見てkを超えない最大の位置にある店舗か、k以上で最小の位置にある店舗である。
 * この両方をスタート地点として、時計回りと反時計回りの両方について距離を求め、最小値を採用すればよい。
 *
 * オーダーは O((M+N) log N)。
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while(true) {
        int D, N, M;
        cin >> D;
        if(!D) break;
        cin >> N >> M;

        vector<int> shops;
        shops.push_back(0);
        for(int i = 1; i < N; ++i) {
            int d;
            cin >> d;
            shops.push_back(d);
        }

        int ans = 0;
        sort(shops.begin(), shops.end());
        while(M--) {
            int k;
            cin >> k;
            vector<int>::iterator it = lower_bound(shops.begin(), shops.end(), k);
            vector<int>::iterator it2;
            if(it == shops.begin()) it2 = shops.end()-1;
            else it2 = it-1;
            int d1 = (abs(*it-k+D)) % D;
            int d2 = (abs(*it2-k+D)) % D;
            //cout << min(d1, d2) << endl;
            ans += min(min(d1, D-d2) % D, min(d2, D-d2) % D);
            //ans += min(d1, d2);
        }
        cout << ans << endl;
    }
    return 0;
}
