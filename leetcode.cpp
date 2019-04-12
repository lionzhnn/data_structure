//21. Merge Two Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp1,*temp2;
        ListNode *temp=new ListNode(0);
        temp1=l1;
        temp2=l2;
        ListNode *temp3=temp;
        if(!l1) return l2;
        if(!l2) return l1;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val < temp2->val)
            {
                temp->next=new ListNode(temp1->val);
                temp1=temp1->next;
            }
            else
            {
                temp->next=new ListNode(temp2->val);
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        if(temp1)
        {
            temp->next=temp1;
        }
        if(temp2)
        {
            temp->next=temp2;
        }
        temp=temp3;
        temp=temp->next;
        delete temp3;
        return temp;
}
//26. Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) 
            return 0;
        if(nums.size() ==1)
            return 1;
        auto baseNum=nums[0];
        auto curNum=nums[1];
        int indexForward=1;
        int length=1;
        for(int j=1;j<nums.size();j++)
        {
            if(curNum==baseNum)
            {
                //前移一位
                for(int i=indexForward;i!=(nums.size()-1);i++)
                {
                    nums[i]=nums[i+1];
                }
                //把重复的数值放到最后
                nums[nums.size()-1]=curNum;
                curNum=nums[indexForward];
            }
            if(curNum>baseNum)
            {
                baseNum=curNum;
                indexForward=indexForward+1;
                length=length+1;
                if(indexForward<nums.size())
                    curNum=nums[indexForward];
            }
        }
        return length;
}
