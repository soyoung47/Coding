//https://programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";

    //1�ܰ�: �ҹ��ڷ� ġȯ
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    //2�ܰ�: �ҹ���, ����, -, _, . ������ ��� ���� ����
    string tmp = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        char ch = new_id[i];
        if (isalpha(ch) || isdigit(ch) || ch == '-' || ch == '_' || ch == '.')
            tmp += ch;
    }
    new_id = tmp;

    //3�ܰ�: 2�� �̻� ���ӵ� .�� �ϳ��� .�� ġȯ
    bool check = false;
    tmp = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        char ch = new_id[i];
        if (ch == '.')
        {
            if (check)   continue;
            check = true;
        }
        else if (check)
            check = false;

        tmp += ch;
    }
    new_id = tmp;

    //4�ܰ�: ó�� Ȥ�� ���� ��ġ�� . ����
    if (new_id[0] == '.')
        new_id = new_id.substr(1);
    if (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();

    //5�ܰ�: ���ڿ��̸�, new_id�� 'a' ����
    if (new_id.empty())  new_id = "a";

    //6�ܰ�: ���̰� 16�� �̻��̸�, ù 15���� ���� ������ ������ ���� ��� ����
    if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
    if (new_id[new_id.size() - 1] == '.')   new_id.pop_back();

    //7�ܰ�: ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �ɶ����� �ݺ��ؼ� ���� �߰�
    if (new_id.size() <= 2)
    {
        char last = new_id[new_id.size() - 1];
        while (new_id.size() < 3)
        {
            new_id += last;
        }
    }

    answer = new_id;

    return answer;
}