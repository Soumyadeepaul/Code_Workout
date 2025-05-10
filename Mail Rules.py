#https://www.naukri.com/code360/problems/mail-rules_19247255

from typing import List

def count_unique_emails(emails: List[str]) -> int:
    # Write your code here
    for i in range(len(emails)):
        mail=emails[i]
        domain=mail
        local=''
        pluse=0
        for j in domain:
            if j=='@':
                break
            else:
                if j=='+':
                    pluse=1
                elif pluse==1:
                    pass
                elif j=='.':
                    pass
                else:
                    local+=j
            domain=domain[1:]
        emails[i]=local+domain

    return len(set(emails))
