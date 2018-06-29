#include<iostream>
#include<fstream>//文件流——ifstream输入流——ofstream输出流
#include<sstream>//字符串流——istringstream输入流——ostringstream输出流——stringstream输入输出流
#include<string>//erase函数——删除
#include<vector>//向量——能够存放任何类型的动态数组
#include<list>
using namespace std;

//删除字符串中空格，制表符tab等无效字符—
string Trim(string& str)
{
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

//计算平均值
class Mark
{
private:
    int judge[5];
    int max,min,average;
public:
    void setinfo(int judge_[]){
        judge[0]=judge_[0];judge[1]=judge_[1];judge[2]=judge_[2];judge[3]=judge_[3];judge[4]=judge_[4];
    }
    void traverse(){
        int i;
        int max=0,min=4;
        for(i=0;i<5;++i){
            if(judge[max]<judge[i])
                max=i;
            if(judge[min]>judge[i])
                min=i;
        }
        average=(judge[0]+judge[1]+judge[2]+judge[3]+judge[4]-judge[max]-judge[min])/3;
    }
};

int main()
{
    string name;
    string numbers;
    string sex;
    string phoneNo;
    string judge1,judge2,judge3,judge4,judge5;
    int dateofbirth;
    int judge[5];
    list<string> name_;
    list<string> numbers_;
    list<string> sex_;
    list<string> phoneNo_;
    list<int> dateofbirth_;
    list<int> average;
    ifstream fin("test1.csv");
    string line;
    while(getline(fin,line)){
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin,field,',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
            
        }
    return 0;
}
