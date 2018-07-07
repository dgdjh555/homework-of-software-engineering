#include<iostream>
#include<fstream>//文件流——ifstream输入流——ofstream输出流
#include<sstream>//字符串流——istringstream输入流——ostringstream输出流——stringstream输入输出流
#include<string>//erase函数——删除
#include<vector>//向量——能够存放任何类型的动态数组
#include<list>
using namespace std;
template <class T>
//删除字符串中空格，制表符tab等无效字符—
T Trim(T& str)
{
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

int ave(list<string> a){//把字符串型转换成整形并计算平均值
    int sum;
    int max=0;
    int min=101;
    string c;
    list<string>::iterator b;
    b=a.begin();
    for(;b!=a.end();++b){
        sum+=atoi(b->c_str());
        if(max<atoi(b->c_str()))
            max=atoi(b->c_str());
        if(min>atoi(b->c_str()))
            min=atoi(b->c_str());
    }
    return sum-max-min;
}


int main()
{
    int i=0;//行
    int judge=0;//裁判人数
    int l;
    list<string> name;
    list<string> numbers;
    list<string> sex;
    list<string> phoneNo;
    list<string> dateofbirth;
    list<string> cla;
    list<int> average;
    list<string> judge_;
    ifstream fin("/Users/20171105124dgx/Downloads/homework_of_software_engineering/studentdata.csv");
    string line;
    vector<string>::iterator fie;
    while(getline(fin,line)){
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin,field,',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        if(i==0){//判断有多少名裁判
            for(fie=fields.begin();fie!=fields.end();++fie)
                ++judge;
            judge-=6;
            ++i;
        }
        else{
            //一组数据传参
            numbers.push_back(Trim(fields[0]));
            name.push_back(Trim(fields[1]));
            sex.push_back(Trim(fields[2]));
            dateofbirth.push_back(Trim(fields[3]));
            cla.push_back(Trim(fields[4]));
            phoneNo.push_back(Trim(fields[5]));
            for(l=0;l<judge;++l)
                judge_.push_back(Trim(fields[6+l]));
            average.push_back(ave(judge_)/(judge-2));
            judge_.clear();
            ++i;
        }
    }
    average.sort();
    ofstream  out("/Users/20171105124dgx/Downloads/homework_of_software_engineering/studentdataout.csv");
    list<string>::iterator nu,na,se,ph,cl,da;
    list<int>::iterator av;
    nu=numbers.begin();na=name.begin();se=sex.begin();ph=phoneNo.begin();cl=cla.begin();da=dateofbirth.begin();av=average.begin();
    if(out.is_open()){
        out<<"numbers,name,sex,dateofbirth,class,phoneNO,average\n";
        for(;nu!=numbers.end();++nu,++na,++se,++da,++cl,++ph,++av){
            out<<*nu<<","<<*na<<","<<*se<<","<<*da<<","<<*cl<<","<<*ph<<","<<*av<<endl;
        }
        out.close();
    }
    return 0;
}
