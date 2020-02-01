#define forn(i,n)           for(int i=0;i<n;i++)
#define pb(b)               push_back(b)
int n;
    cin >> n;
    int a[n+1],b[n+1];
    forn(i,n)cin>>a[i];
    forn(i,n)cin>>b[i];

    vector<int>ans;

    forn(i,n){
        int app=1e9;
        forn(j,n)app=min( abs(a[i]-b[j]), app );
        ans.pb(app);
    }
    int answ=-1;
    forn(i,n)answ=max(answ,ans[i]);

    cout<<answ;
