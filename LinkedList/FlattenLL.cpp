/*

algorithm

step-1.down=head     ,    right=head->next  
step-2.apply recursion on right part
step-3. down->next=null
step-4.merge (down,right)
step-5.return ans;



 Node * merge(Node*down,Node*right){
	 Node*result=new Node(-1);
	 Node*temp=result;

	 if (down==NULL){
		 return right;
	 }

	 if (right==NULL){
		 return down;
	 }

	 while(down!=NULL  &&   right!=NULL){
		 if(down->data  <  right->data){
			temp ->child=down;
			 temp=down;
			 down=down->child;

		 }

		 else{
			 temp->child=right;
			 temp=right;
			 right=right->child;
		 }
	 }

	 while(down!=NULL){
		 temp ->child=down;
			 temp=down;
			 down=down->child;


	 }
	 
	 while(right!=NULL){
		 temp->child=right;
			 temp=right;
			 right=right->child;
	 }

	 result=result->child;
	 return result;

 }
Node* flattenLinkedList(Node* head) 
{   


	if (head->next==NULL){
		return head;
	}
	Node*down=head;
	Node*right=head->next;
	right=flattenLinkedList(right);
	down->next=NULL;
	Node*ans=merge(down,right);

	return ans;
}


















*/