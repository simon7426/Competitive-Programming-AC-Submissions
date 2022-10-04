class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x: (-x[0], x[1]))
        
        max_defense = 0
        weak_count = 0
        
        for _, defense in properties:
            # for any given element:
            # - every attack must be less than or equal to what we have already seen
            # - if the attack is the same, then the defense must be greater than what we have already seen for this attack value
            if defense < max_defense:
                weak_count += 1
            else:
                max_defense = defense
            
        return weak_count