//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        if (head == NULL || k <= 1)
            return head;

        struct node *prev_group_tail = NULL; // To keep track of the tail of the previous group
        struct node *current = head;

        // Traverse through the linked list in groups of k
        while (current != NULL)
        {
            int count = 0;
            struct node *group_head = current; // Head of the current group
            struct node *prev = NULL; // To keep track of the previous node in the current group

            // Reverse the k nodes in the current group
            while (current != NULL && count < k)
            {
                struct node *nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
                count++;
            }

            // After reversing, 'prev' will be the head of the reversed group
            if (prev_group_tail != NULL)
            {
                // Connect the tail of the previous group with the head of the current group
                prev_group_tail->next = prev;
            }
            else
            {
                // If this is the first group, update the head of the entire linked list
                head = prev;
            }

            // Find the tail of the current group and update prev_group_tail
            struct node *group_tail = group_head;
            while (group_tail->next != NULL)
            {
                group_tail = group_tail->next;
            }
            prev_group_tail = group_tail;
        }

        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends