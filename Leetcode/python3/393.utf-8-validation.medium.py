class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        i = 0
        while i < len(data):
            skip, mask = 0, 1 << 7
            while data[i] & mask:
                skip += 1
                mask >>= 1
                
            if skip == 1 or skip > 4: return False
            if any(not x & 1<<7 or x & 1<<6 for x in data[i+1:i+skip]): return False
            
            i += max(1, skip)
        return i == len(data)