class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        ans = []
        products.sort()
        for i in range(1, len(searchWord)+1):
            products = list(filter(lambda x: x.startswith(searchWord[:i]), products))
            ans.append(products[:3])
        return ans