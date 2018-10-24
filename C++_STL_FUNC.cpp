#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
int comp1(int x)
{
    if(x%2==0)
        return 1;
    return 0;
}
int comp2(int i,int j)
{
    return i>j;
}
int main()
{
    steady_clock::time_point t1 = steady_clock::now();
    string s1="aacd";
    string s2="abcd";
    cout<<lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end())<<endl;
    int cnt=0;
    sort(s2.begin(),s2.end());
    reverse(s2.begin(),s2.end());
    do
    {
        cout<<++cnt<<" "<<s2<<endl;
    }while(prev_permutation(s2.begin(),s2.end()));
    cout<<min(2.3,3.15)<<endl;
    cout<<max('s','f')<<endl;
    int arr[]={1,2,3,4,6,5,8,0,9};
    auto u=minmax({1,2,3,4,6,5,8,0,9});
    auto utr=minmax_element(arr,arr+9);
    cout<<*utr.first<<" "<<*utr.second<<endl;
    cout<<u.first<<" "<<u.second<<endl; // min and max
    cout<<*min_element(arr,arr+9)<<" "<<*max_element(arr,arr+9)<<endl;
    vector<int>vec(arr,arr+10);
    if(!is_heap(vec.begin(),vec.end()))
        make_heap(vec.begin(),vec.end());
    auto last=is_heap_until(vec.begin(),vec.end());
    int lst=last-vec.begin();
    cout<<lst<<endl;
    pop_heap(vec.begin(),vec.end());
    vec.pop_back();
    vec.push_back(99);
    push_heap(vec.begin(),vec.end());
    int a1[]={4,5,3,2};
    int a2[]={1,6,2,7};
    sort(a1,a1+4);
    sort(a2,a2+4);
    vec.clear();
    vec.resize(8);
    // UNCOMMENT  merge(a1,a1+4,a2,a2+4,vec.begin());
    auto it1=copy(a1,a1+4,vec.begin());
    cout<<*it1<<endl;
    copy(a2,a2+4,it1);
    inplace_merge(vec.begin(),vec.begin()+4,vec.end());
    for(int&xx:vec)
        cout<<xx<<" ";
    cout<<endl;
    cout<<includes(vec.begin(),vec.end(),a1,a1+4)<<endl;
    auto it2=set_union(a1,a1+4,a2,a2+4,vec.begin());
    vec.resize(it2-vec.begin());
    for(int&xx:vec)
        cout<<xx<<" ";
    cout<<endl;
    auto it3=set_intersection(a1,a1+4,a2,a2+4,vec.begin());
    vec.resize(it3-vec.begin());
    for(int&xx:vec)
        cout<<xx<<" ";
    cout<<endl;
    // similarly set_diiference and set_symmetric_difference
    int a3[]={1,2,3,3,3,4,5};
    cout<<lower_bound(a3,a3+7,3)-a3<<" ";
    cout<<upper_bound(a3,a3+7,3)-a3<<endl;
    cout<<equal_range(a3,a3+7,3).first-a3<<" "<<equal_range(a3,a3+7,3).second-a3<<endl;
    int a4[]={1,2,3,4,5,6,7,8,9};
    if(!is_partitioned(a4,a4+9,comp1))
    {
        cout<<"partitioning...\n";
        // UNCOMMENT partition(a4,a4+9,comp1);
        stable_partition(a4,a4+9,comp1);
        auto it5=partition_point(a4,a4+9,comp1);
        cout<<*it5<<endl;
        for(int i=0;i<9;i++)
            cout<<a4[i]<<" ";
        cout<<endl;
    }
    stable_sort(a4,a4+9);
    for(int i=0;i<9;i++)
            cout<<a4[i]<<" ";
    cout<<endl;
    if(is_sorted(a4,a4+9))
        cout<<"sorted\n";
    int ar[]={1,3,4,6,7,8,9,2,3};
    cout<<*is_sorted_until(ar,ar+9)<<endl;
    vector<int> myvector;
    for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
    random_shuffle (myvector.begin(), myvector.end());
    random_shuffle (myvector.begin(), myvector.end());
    for (std::vector<int>::iterator ite=myvector.begin(); ite!=myvector.end(); ++ite)
        cout << ' ' << *ite;
    cout << '\n';
    nth_element (myvector.begin(), myvector.begin()+5, myvector.end());
    for (std::vector<int>::iterator ite=myvector.begin(); ite!=myvector.end(); ++ite)
        cout << ' ' << *ite;
    cout << '\n';
    nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),comp2);
    cout << "myvector contains:";
    for (std::vector<int>::iterator ite=myvector.begin(); ite!=myvector.end(); ++ite)
        cout << ' ' << *ite;
    cout << '\n';
    partial_sort(myvector.begin(),myvector.begin()+3,myvector.end()); // can be given binary predicate too
    for (std::vector<int>::iterator ite=myvector.begin(); ite!=myvector.end(); ++ite)
        cout << ' ' << *ite;
    cout << '\n';
    rotate(myvector.begin(),myvector.begin()+4,myvector.end());
    for (std::vector<int>::iterator ite=myvector.begin(); ite!=myvector.end(); ++ite)
        cout << ' ' << *ite;
    cout << '\n';
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() << " seconds.";

    return 0;
}
