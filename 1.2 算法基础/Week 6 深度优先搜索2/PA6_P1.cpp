#include <iostream>
#include <string>
using namespace std;
const int MAXN = 101;

class Shredding{
    private:
    int largest, target;
    string::size_type strsize;
    string initstr, ansstr, pos[MAXN];
    public:
    bool init();
    void DFS(int index, int depth, int sum);
    void print();
};

bool Shredding::init(){
    cin >> target >> initstr;
    if(target ==0 && initstr == "0") return false;
    return true;
}

void Shredding::DFS(int index, int depth, int sum){
    if(index == strsize){
        if(largest < sum){
            largest = sum;
            ansstr = pos[0];
            for(int i = 1; i < depth; i ++){
                ansstr += " " + pos[i];
            }
        }
        else if(largest == sum) ansstr = "rejected";
    }
    else{
        int num = 0;
        string tmp = "";
        for(int ix = index; ix < strsize; ix++){
            tmp += initstr[ix];
            pos[depth] = tmp;
            num = num * 10 + (initstr[ix] - '0');
            if(num + sum > target) break;
            DFS(ix+1, depth+1, num+sum);
        }
    }
}

void Shredding::print(){
    ansstr = "error";
    largest = 0;
    strsize = initstr.size();
    DFS(0,0,0);
    if (ansstr == "error" || ansstr == "rejected"){
        cout << ansstr << endl;
    }
    else{
        cout << largest << " " << ansstr << endl;
    }
}

int main(){
    Shredding sh;
    while(sh.init()){
        sh.print();
    }
    return 0;
}