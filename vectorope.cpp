#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>vct(n);
    for(int i=0;i<n;i++)
    {
        cin>>vct[i];
    }
    for_each(vct.begin(),vct.end(),[] (int i) 
    {
        cout<<i<<endl;
    });
    cout<<"find function:"<<endl;
    auto it=find(vct.begin(),vct.end(),2);
    if (it != vct.end())
    {
        cout << "Found: " << *it;
    }
    cout<<"even numbers:"<<endl;
    auto is_even=[](int x){ return x%2==0;};
    auto it1=find_if(vct.begin(),vct.end(),is_even);
    if(it1 != vct.end()) cout<<"first even:"<<*it1;
}


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"enter n value:"<<endl;
     cin>>n;
    vector<int>vct(n);
    for(int i=0;i<n;i++)
    {
        cin>>vct[i];
    }
     cout<<"even numbers:"<<endl;
    auto is_even=[](int x){ return x%2==0;};
    auto it1=find_if(vct.begin(),vct.end(),is_even);
    if(it1 != vct.end()) cout<<"first even:"<<*it1;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>vct(n);
    for(int i=0;i<n;i++)
    {
        cin>>vct[i];
    }
    for_each(vct.begin(),vct.end(),[] (int i) 
    {
        cout<<i<<endl;
    });
    
    cout<<"even numbers:"<<endl;
    auto is_even=[](int x){ return x%2==0;};
    auto it1=find_if(vct.begin(),vct.end(),is_even);
    if(it1 != vct.end()) cout<<"first even:"<<*it1;
}


#include <iostream>
#include <vector>
#include <algorithm>  // For std::find
using namespace std;
int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    // Use std::find to search for the value 3
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        cout << "Found: " << *it << "\n";
    } else {
       cout << "Value not found.\n";
    }
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"enter n value";
    cin>>n;
    //vector declaration
     vector<int>vt(n);
    for(int i=0;i<n;i++)
    {
        cin>>vt[i];
    }    
    //push_back opeartion
    vt.push_back(25);
    //pop_back opeartion
    vt.pop_back();
    cout<<"front element:"<<vt.front()<<endl;
    cout<<"back elemnts"<<vt.back()<<endl;
    cout<<"size of vector"<<vt.size()<<endl;
    cout<<"capacity of vector"<<vt.capacity()<<endl;
    vt.erase(vt.begin()+2);
    for(int x:vt)
    {
        cout<<x<<endl;
    }
    vt.clear();
    cout<<vt.size();
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"enter n value:"<<endl;
    cin>>n;
    vector<int>vct(n);
    for(int i=0;i<n;i++)
    {
        cin>>vct[i];
    }
    int count_value;
    cout<<"enter the value to be count:"<<endl;
    cin>>count_value;
    int result=count(vct.begin(),vct.end(),count_value);
    cout<<"count number of time it occur:"<<result;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>vct1={10,20,30,40};
    vector<int>vct2={100,200,300};
    vector<int>res(vct1.size()+vct2.size());
   auto it= set_union(vct1.begin(),vct1.end(),vct2.begin(),vct2.end(),res.begin());
    res.resize(it-res.begin());
    for(int x:res)
    {
        cout<<x<<endl;
    }
}