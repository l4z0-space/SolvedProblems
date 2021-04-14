#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
#define sorted(a)           sort(a.begin(),a.end())
#define reversed(a)         reverse(a.begin(),a.end())
#define print(a)            cout<<a;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

unordered_map<int,int> diff;
struct Point {

    double x, y;

    bool operator<(Point p)
    {

        return x < p.x || (x == p.x && y < p.y);
    }
};


double CP(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> CH(vector<Point> A)
{
    int n = A.size(), k = 0;

    if (n <= 3)
        return A;

    vector<Point> ans(2 * n);
    sort(A.begin(), A.end());

    for (int i = 0; i < n; ++i) {

        while (k >= 2 && CP(ans[k - 2],ans[k - 1], A[i]) <= 0)
            k--;
        ans[k++] = A[i];
    }


    for (size_t i = n - 1, t = k + 1; i > 0; --i) {
        while (k >= t && CP(ans[k - 2],ans[k - 1], A[i - 1]) <= 0)k--;
        ans[k++] = A[i - 1];
    }

    ans.resize(k - 1);

    return ans;
}


double area( vector<Point>P){
    double result =0.0,x1,x2,y1,y2;

    forn(i,(int)P.size()-1){
        x1 = P[i].x;
        x2 = P[i+1].x;
        y1 = P[i].y;
        y2 = P[i+1].y;
        result += (x1*y2 - x2*y1);

    }
    return fabs(result/2.0);

}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Point> vec;

    int n;cin>>n;

    while(n--){
        double a,b;
        cin>>a>>b;
        Point ss;
        ss.x = a;
        ss.y=b;
        vec.pb(ss);
    }

    vector<Point> news = CH(vec);

    news.pb(news[0]);
   // sorted(vec);

    cout<<fixed<< setprecision(1)<<area(news);
}


