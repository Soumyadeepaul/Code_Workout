#

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=n-2;
	int previous=arr[n-1];
	while (i>-1){
		if (arr[i]==previous){
			//loop back
			for(int j=i+1;j<arr.size();j++){
					arr[j-1]=arr[j];
			}
			arr.erase(arr.begin()+arr.size()-1);	
		}
		else{
			previous=arr[i];
		}
		i--;
	}
	int l=0;
	l=arr.size();
	return l;
}
