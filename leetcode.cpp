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
        int length=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[length-1] != nums[i])
                nums[length++]=nums[i];
        }
        return length;
}
//27. Remove Element
int removeElement(vector<int>& nums, int val) {
        int lenght=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[lenght++]=nums[i];
            }
        }
        return lenght;        
}
//28. Implement strStr()
int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(haystack.size()<needle.size())
            return -1;
        for(int i=0;i<=(haystack.size()-needle.size());i++)
        {
            if(haystack[i]==needle[0])
            {
                int j;
                for(j=1;j<needle.size();j++)
                {
                    if(haystack[i+j]!=needle[j])
                    {
                        break;
                    }
                }
                if(j==needle.size())
                    return i;
            }
        }
        return -1;        
}
//717. 1-bit and 2-bit Characters
bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1)
            return true;
        if(bits[bits.size()-2]==0) //倒数第二个字符为0，最后一个零只能为第一个字符
            return true;
        int i=0;
        while(i<bits.size())
        {
            if(bits[i]==1) //跳过第二个字母的第二个字符0或者1
                i=i+2;
            else
                i=i+1; //跳过第一个字符
            if(i==(bits.size()-1)) //到达最后一个字符0
                return true;
        }
        return false;        
}
