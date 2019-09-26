#include<bits/stdc++.h>
using namespace std;


int mazepath(int sr , int sc , int er, int ec , string ans)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<" ";
        return 1;
    }

    int count = 0 , x = 0, y  =0 ;
    if(sc+1<=ec)
    {
        x = mazepath(sr , sc+1 , er, ec ,  ans + "H");
    }
    if(sr + 1 <= er)
    {
        y = mazepath(sr+1 , sc , er , ec ,  ans + "V" );
    }
    return count;
}


//diagnol-problem
int sumlevels = 0,  maxlevel = 0;

int mazepathdiag(int sr , int sc , int er, int ec , string ans , int level)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<" ";
        sumlevels += level;
        maxlevel = max(maxlevel , level);
        return 1;
    }

    int count = 0;
    if(sc+1<=ec)
    {
        count += mazepathdiag(sr , sc+1 , er, ec ,  ans + "H" , level + 1);
    }
    if(sr + 1 <= er)
    {
        count += mazepathdiag(sr+1 , sc , er , ec ,  ans + "V" , level+1);
    }
    if(sr + 1 <= er && sc +1 <= ec)
    {
        count += mazepathdiag(sr+1 , sc+1 , er , ec ,  ans + "D" , level + 1);
    }
    
    return count;
}

// multiplepaths

int jumppath(int sr , int sc , int er , int ec, string ans)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<" ";
        return 1;
    }
    int count = 0;
    for(int jumps = 1; sr+jumps <= er; jumps++)
    {
        count += jumppath(sr+jumps , sc , er , ec , ans + "V" + to_string(jumps));
    }
    for(int jumps = 1; sc+jumps <= ec; jumps++)
    {
        count += jumppath(sr , sc + jumps , er , ec , ans + "H" + to_string(jumps));
    }
    for(int jumps = 1; sr+jumps <= er && sc + jumps<=ec; jumps++)
    {
        count += jumppath(sr+jumps , sc + jumps , er , ec , ans + "D" + to_string(jumps));
    }
    return count;
}

// boardpath
int boardpath(int si, int ei , string ans)
{
    if(si == ei)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int dice = 1; dice <= 6 && si + dice <= ei; dice++)
    {
        count += boardpath(si + dice, ei, ans + to_string(dice));
    }
    return count;
}

void solve()
{
    cout<< mazepathdiag(0,0,2,2,"", 0);
    cout<<endl;
    cout<<" sumlevel " <<sumlevels<<endl;
    cout<<" maxlevel "<<maxlevel<<endl; 
    cout<<endl<<" boardpath "<< boardpath(1,10,""); 

}
int main()
{
    solve();
}