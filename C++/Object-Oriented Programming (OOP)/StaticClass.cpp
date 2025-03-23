#include <iostream>

class Product{
    double productCost;
    double productSale;
    
    public :
    static double totalCost;
    
    Product(double buyPrice){
        productCost = buyPrice + 35.50;
        totalCost += productCost;
    }

        double getProductSale(){
        productSale = productCost + 6.50;
        return productSale;
    }
};

double Product::totalCost = 0.0;

int main(){
    Product Shampoo(8.90) , brush(3.50);
    std::cout << "Product Price: \n" << "Shampoo RM : " << Shampoo.getProductSale() << "\nBrush RM : " << brush.getProductSale() << std::endl;
    std::cout << "Total Cost: " << Product::totalCost << std::endl;
    std::cout << "Total Cost: " << brush.totalCost << std::endl;
    return 0;
}