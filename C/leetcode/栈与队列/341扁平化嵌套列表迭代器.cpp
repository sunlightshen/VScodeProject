#include<iostream>
#include<vector>
#include<stack>

using namespace std; 


class NestedIterator {
public:
    stack<vector<NestedInteger>::iterator> nests, layer_end;  
    //����ջ���layer��ʼ�ͽ�����iterator
    NestedIterator(vector<NestedInteger> &nestedList) {
        nests.push(nestedList.begin());
        layer_end.push(nestedList.end());
    }

    int next() {
        //����nests.top
        //��nestsջ����Ϊ��һ��������
        int x = nests.top()->getInteger();
        
        while(++nests.top()==layer_end.top()){ //�ѵ�Listβ
            nests.pop();
            layer_end.pop();
            if(nests.empty()) break;
        }
        
        return x;
    }

    bool hasNext() {
        //����:����һ��integer�ĵ���������ջ
        while(nests.size()){
            //[[]], [[],1,2]�����
            if(nests.top()==layer_end.top()) {
                nests.pop(); layer_end.pop(); 
                if(nests.empty()) return false; //û��layer��������
                nests.top()++; continue;
            }
            //case1������
            if(nests.top()->isInteger())
                return true;
            //case2: �б�
            vector<NestedInteger> &list = nests.top()->getList();
            //����list��Ԫ�ص�����
            nests.push(list.begin());
            layer_end.push(list.end());//����list.end
        }
        return false;
    }
    
}; 
int main()
{
	retunr 0;
}
