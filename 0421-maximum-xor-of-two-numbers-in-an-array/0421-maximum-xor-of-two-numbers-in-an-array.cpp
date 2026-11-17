class Solution {
public:
    struct Node {
        Node* links[2];
        Node() {
            links[0] = links[1] = NULL;
        }
    };
    Node* root = new Node();
    
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums) {
            insert(num);
        }

        int maxi = 0;
        for (int num : nums) {
            maxi = max(maxi, findMax(num));
        }
        return maxi;
    }
    
    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->links[bit] == NULL) {
                node->links[bit] = new Node();
            }

            node = node->links[bit];
        }
    }
    
    int findMax(int num) {
        Node* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if (node->links[opposite] != NULL) {
                ans |= (1 << i);
                node = node->links[opposite];
            }
            else {
                node = node->links[bit];
            }
        }
        return ans;
    }

};