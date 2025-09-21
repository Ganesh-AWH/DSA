#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Node for category or product 
struct Node { 
char name[50]; 
int isProduct;      
// 0 = category, 1 = product 
int product_ID; 
float price; 
int quantity; 
struct Node* child; 
struct Node* sibling; 
}; 
// Create a category 
struct Node* createCategory(char name[]) { 
struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
strcpy(node->name, name); 
node->isProduct = 0; 
node->child = node->sibling = NULL; 
return node; 
} 
// Create a product 
struct Node* createProduct(char name[], int id, float price, int qty) { 
struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
strcpy(node->name, name); 
node->isProduct = 1; 
node->product_ID = id; 
node->price = price; 
node->quantity = qty; 
node->child = node->sibling = NULL; 
return node; 
} 
// Add child to parent 
void addChild(struct Node* parent, struct Node* child) { 
if (!parent->child) 
parent->child = child; 
else { 
struct Node* temp = parent->child; 
while (temp->sibling) temp = temp->sibling; 
temp->sibling = child; 
} 
} 
// Print catalog 
void printCatalog(struct Node* root, int level) { 
if (!root) return; 
for (int i = 0; i < level; i++) printf("  "); 
if (root->isProduct) 
printf("Product: %s (ID:%d, Price:%.2f, Qty:%d)\n", root->name, root->product_ID, 
root->price, root->quantity); 
else 
printf("Category: %s\n", root->name); 
printCatalog(root->child, level + 1); 
printCatalog(root->sibling, level); 
} 
// Update product price and quantity 
void updateProduct(struct Node* root, int id, float price, int qty) { 
if (!root) return; 
if (root->isProduct && root->product_ID == id) { 
root->price = price; 
root->quantity = qty; 
printf("Updated Product ID %d: Price %.2f, Qty %d\n", id, price, qty); 
} 
updateProduct(root->child, id, price, qty); 
updateProduct(root->sibling, id, price, qty); 
} 
// Main function 
int main() { 
struct Node* catalog = createCategory("Electronics"); 
struct Node* laptops = createCategory("Laptops"); 
addChild(catalog, laptops); 
struct Node* gaming = createCategory("Gaming Laptops"); 
addChild(laptops, gaming); 
struct Node* prod1 = createProduct("BrandX Laptop", 101, 1500.0, 10); 
addChild(gaming, prod1); 
struct Node* prod2 = createProduct("BrandY Laptop", 102, 1800.0, 5); 
addChild(gaming, prod2); 
printf("--- Product Catalog ---\n"); 
printCatalog(catalog, 0); 
// Update product 
updateProduct(catalog, 101, 1450.0, 12); 
printf("\n--- Updated Catalog ---\n"); 
printCatalog(catalog, 0); 
return 0; 
}