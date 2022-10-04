class Solution:
    def myAtoi(self, s: str) -> int:
        ret = 0
        started = False
        finished = False
        is_neg = False
        
        for let in s:
            if finished:
                break
            if not started:
                if let == " ":
                    continue
                elif ((let>='0' and let<='9') or let=='+' or let=='-'):
                    started=True
                    if let=='-':
                        is_neg = True
                    elif let=='+':
                        is_neg = False
                    else:
                        ret = int(let)
                else:
                    finished = True
            else:
                if let>='0' and let<='9':
                    if ret>2**31:
                        finished=True
                        continue
                    ret *= 10
                    ret+=int(let)
                else:
                    finished = True
        if ret>=2**31:
            ret = 2**31
            if not is_neg:
                ret-=1
        if is_neg:
            ret*= -1
        return ret