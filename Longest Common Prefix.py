#https://www.naukri.com/code360/problems/longest-common-prefix_2090383


def longestCommonPrefix(arr, n):
    # Write your code here
    # Return a string
    maxi=''
    minn='xgfddhggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggcvvhvgvvvnvnbcvbcbvcbgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggcghcghfgcghgcgfcgcvgfyhgfhgkugukgkhkhkugjhvgvgcfccbvvhjbhjhgchcfcddvjhhcgccgcbagdgashgchsadcvzhjvcjashvhavschasvcashdgasgfhagshdgaskhdgashgfjgahsvgcvghadvgvasghvcngasvvzgdvchjvasc'
    for i in arr:
        if len(i)>len(maxi):
            maxi=i
        elif len(i)<len(minn):
            minn=i
    prefix=''
    for i in range(len(minn)):
        if minn[i]==maxi[i]:
            prefix+=minn[i]
    
    for i in arr:
        if i==minn or i==maxi:
            pass
        else:
            j=0
            new=''
            while j<len(prefix):
                if i[j]==prefix[j]:
                    new+=i[j]
                else:
                    break
                j+=1
            prefix=new
    return prefix

