/// ---KMP Algorithm---
/// -Matching two strings
/// -Complexity: O(|S|+|T|)
/// ------------------------

#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;

string S, T; /// Matching S in T
int F[MAXN];
vector<int> ans;

void KMP_Build() {
    int p=F[0]=-1;
    for (int i=1; i<int(S.length()); i++) {
        while (p!=-1 && S[p+1]!=S[i]) p=F[p];
        if (S[p+1]==S[i]) p++;
        F[i]=p;
    }
}

void KMP_Match() {
    int p=-1;
    for (int i=0; i<int(T.length()); i++) {
        while (p!=-1 && S[p+1]!=T[i]) p=F[p];
        if (S[p+1]==T[i]) p++;
        if (p==int(S.length())-1) {
            ans.emplace_back(i-p);
            p=F[p];
        }
    }
}

int main() {
    cin >> S >> T;
    KMP_Build();
    KMP_Match();
    for (int i=0; i<int(ans.size()); i++) {
        if (i!=0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
