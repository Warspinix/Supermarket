#include <iostream>
#include <string>
#include <cctype>
#include "supermarket.h"
using namespace std;

int main() {

        // General Variabless
        int choice, pos, cpos, ppos, category;

        // Customer Variables
        string Old, New;
        Customer * customers=new Customer[3];
        int no_of_customers=0;

        // Product Variables
        int p_id=1;
        string name, temp;
        float price;
        int id, q;
        Product * products=new Product[9];
        int no_of_products=0;

        // Gadget Variables
        string brand, disp;
        int gb;

        // Phone Variables
        int cam, un;
        string con;
        Phone * phones=new Phone[9];
        int no_of_phones=0;

        // Laptop Variables
        string fan, track, kb;
        Laptop * laptops=new Laptop[9];
        int no_of_laptops=0;

        // Cloth Variables
        string mat, type;
        float size;

        // Shirt Variables
        string sb, len;
        Shirt * shirts=new Shirt[9];
        int no_of_shirts=0;

        // Pant Variables
        int pocket;
        string pb;
        Pant * pants=new Pant[9];
        int no_of_pants=0;

        // Bill Variables
        int b_id=1;
        string cphone;
        int pr_id, qty;
        Bill * bills=new Bill[3];
        int no_of_bills=0;

        // Variables for Operator Overloading
        int o1, o2, o1pos, o2pos;
	int np1, np2, t1, t2, t3, t4;

        while (1) {
                cout<<"\n0. Exit\n1. Add Customer\n2. Update Customer Phone Number\n3. Update Customer Name\n4. Display Customer Details\n5. Delete All Customers\n6. Add Product\n7. Display Product Details\n8. Combine Products\n9. Create Bill\n10. Add to Existing Bill\n11. Combine Bill\n12. Generate Bill Details\n";
                cout<<"Your Choice: ";
                cin>>choice;

                if (choice==0)
                        break;
                switch (choice) {
                        case 1:
                                if (no_of_customers<3) {
                                        Customer c;
                                        if (c.getCustomerDetails()) {
                                                cout<<"Customer Added."<<endl;
                                                customers[no_of_customers]=c;
                                                no_of_customers++;
                                        }
                                } else
                                        cout<<"Maximum Customer Count Reached."<<endl;
                                break;
                        case 2:
                                cout<<"\nEnter Old Phone Number: ";
                                cin>>Old;
                                pos=searchCustomer(customers, no_of_customers, Old);
                                if (pos>=0) {
                                        cout<<"Enter New Phone Number: ";
                                        cin>>New;
                                        if (customers[pos].updatePhoneNo(New))
                                                cout<<"Update Successful."<<endl;
                                        else
                                                cout<<"Update Failed."<<endl;
                                } else
                                        cout<<"Phone Number not found."<<endl;
                                break;
                        case 3:
                                cout<<"\nPhone Number: ";
                                cin>>Old;
                                pos=searchCustomer(customers, no_of_customers, Old);
                                if (pos>=0) {
                                        getline(cin, temp);
                                        cout<<"Enter New Name: ";
                                        getline(cin, New);
                                        customers[pos].updateName(New);
                                        cout<<"Update Successful."<<endl;
                                } else
                                        cout<<"Phone Number not found."<<endl;
                                break;
                        case 4:
                                cout<<"\nPhone Number: ";
                                cin>>Old;
                                pos=searchCustomer(customers, no_of_customers, Old);
                                if (pos>=0)
                                        customers[pos].displayCustomerDetails();
                                else
                                        cout<<"Customer not found."<<endl;
                                break;
                        case 5:
                                no_of_customers=0;
                                cout<<"\nAll customers deleted."<<endl;
                                break;
                        case 6:
                                cout<<"Product Category:\n\t1. Gadget\n\t2. Cloth"<<endl;
                                cout<<"Your Choice: ";
                                cin>>category;
                                if (category<1 || category>2)
                                        break;
                                if (no_of_products<10) {
                                        cout<<"\nProduct Name: ";
                                        getline(cin, temp);
                                        getline(cin, name);
                                        cout<<"Price: ";
                                        cin>>price;
                                        cout<<"Quantity: ";
                                        cin>>q;
                                        if (category==1) {
                                                cout<<"Type of Device:\n\t1. Phone\n\t2. Laptop"<<endl;
                                                cout<<"Your Choice: ";
                                                cin>>category;
                                                if (category<1 || category>2)
                                                        break;
                                                cout<<"Brand Name: ";
                                                getline(cin, temp);
                                                getline(cin, brand);
                                                cout<<"Display Technology: ";
                                                getline(cin, disp);
                                                cout<<"Battery Capacity: ";
                                                cin>>gb;
                                                if  (category==1) {
                                                        Phone p;
                                                        p.getProductDetails(p_id, price, name, q);
                                                        p.getGadgetDetails(brand, disp, gb);
                                                        cout<<"No. of Cameras: ";
                                                        cin>>cam;
                                                        cout<<"No. of Unlock Methods: ";
                                                        cin>>un;
                                                        cout<<"Network Connection: ";
                                                        getline(cin, temp);
                                                        getline(cin, con);
                                                        p.getPhoneDetails(cam, un, con);
                                                        phones[no_of_phones]=p;
                                                        cout<<"\n"<<phones[no_of_phones].product_name<<" successfully added."<<endl;
                                                        no_of_phones++;
                                                } else {
                                                        Laptop p;
                                                        p.getProductDetails(p_id, price, name, q);
                                                        p.getGadgetDetails(brand, disp, gb);
                                                        cout<<"Fans: ";
                                                        getline(cin, temp);
                                                        getline(cin, fan);
                                                        cout<<"Trackpad: ";
                                                        getline(cin, track);
                                                        cout<<"Keyboard: ";
                                                        getline(cin, kb);
                                                        p.getLaptopDetails(fan, track, kb);
                                                        laptops[no_of_laptops]=p;
                                                        cout<<"\n"<<laptops[no_of_laptops].product_name<<" successfully added."<<endl;
                                                        no_of_laptops++;
                                                }
                                        } else {
                                                cout<<"Type of Cloth:\n\t1. Shirt\n\t2. Pant"<<endl;
                                                cout<<"Your Choice: ";
                                                cin>>category;
                                                if (category<1 || category>2)
                                                        break;
                                                cout<<"Material: ";
                                                getline(cin, temp);
                                                getline(cin, mat);
                                                cout<<"Type: ";
                                                getline(cin, type);
                                                cout<<"Size: ";
                                                cin>>size;
                                                if  (category==1) {
                                                        Shirt p;
                                                        p.getProductDetails(p_id, price, name, q);
                                                        p.getClothDetails(mat, type, size);
                                                        cout<<"Button Type: ";
                                                        getline(cin, temp);
                                                        getline(cin, sb);
                                                        cout<<"Arm-Length: ";
                                                        getline(cin, len);
                                                        p.getShirtDetails(sb, len);
                                                        shirts[no_of_shirts]=p;
                                                        cout<<"\n"<<shirts[no_of_shirts].product_name<<" successfully added."<<endl;
                                                        no_of_shirts++;
                                                } else {
                                                        Pant p;
                                                        p.getProductDetails(p_id, price, name, q);
                                                        p.getClothDetails(mat, type, size);
                                                        cout<<"No. of Pockets: ";
                                                        cin>>pocket;
                                                        cout<<"Pant Button Type: ";
                                                        getline(cin, temp);
                                                        getline(cin, pb);
							p.getPantDetails(pocket, pb);
                                                        pants[no_of_pants]=p;
                                                        cout<<"\n"<<pants[no_of_pants].product_name<<" successfully added."<<endl;
                                                        no_of_pants++;
                                                }
                                        }
                                        no_of_products++;
                                        cout<<"Product ID: "<<p_id<<endl;
                                        p_id++;
                                } else {
                                        cout<<"Maximum Product Count Reached."<<endl;
                                }
                                break;
                        case 7:
                                cout<<"Product Category:\n\t1. Gadget\n\t2. Cloth"<<endl;
                                cout<<"Your Choice: ";
                                cin>>category;
                                if (category<1 || category>2)
                                        break;
                                if (category==1) {
                                        cout<<"Type of Device:\n\t1. Phone\n\t2. Laptop"<<endl;
                                        cout<<"Your Choice: ";
                                        cin>>category;
                                        if (category<1 || category>2)
                                                break;
                                        if (category==1) {
                                                cout<<"Product ID: ";
                                                cin>>id;
                                                pos=search(phones, no_of_phones, id);
                                                if (pos>=0) {
                                                        phones[pos].displayProductDetails();
                                                        phones[pos].displayGadgetDetails();
                                                        phones[pos].displayPhoneDetails();
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        } else {
                                                cout<<"Product ID: ";
                                                cin>>id;
                                                pos=search(laptops, no_of_laptops, id);
                                                if (pos>=0) {
                                                        laptops[pos].displayProductDetails();
                                                        laptops[pos].displayGadgetDetails();
                                                        laptops[pos].displayLaptopDetails();
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        }
                                } else {
                                        cout<<"Type of Cloth:\n\t1. Shirt\n\t2. Pant"<<endl;
                                        cout<<"Your Choice: ";
                                        cin>>category;
                                        if (category<1 || category>2)
                                                break;
                                        if (category==1) {
                                                cout<<"Product ID: ";
                                                cin>>id;
                                                pos=search(shirts, no_of_shirts, id);
                                                if (pos>=0) {
                                                        shirts[pos].displayProductDetails();
                                                        shirts[pos].displayClothDetails();
                                                        shirts[pos].displayShirtDetails();
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        } else {
                                                cout<<"Product ID: ";
                                                cin>>id;
                                                pos=search(pants, no_of_pants, id);
                                                if (pos>=0) {
                                                        pants[pos].displayProductDetails();
                                                        pants[pos].displayClothDetails();
                                                        pants[pos].displayPantDetails();
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        }
                                }
                                break;
			case 8:
				cout<<"Product Category:\n\t1. Gadget\n\t2. Cloth"<<endl;
                                cout<<"Your Choice: ";
                                cin>>category;
                                if (category<1 || category>2)
                                        break;
                                if (category==1) {
                                        cout<<"Type of Device:\n\t1. Phone\n\t2. Laptop"<<endl;
                                        cout<<"Your Choice: ";
                                        cin>>category;
                                        if (category<1 || category>2)
                                                break;
                                        if (category==1) {
                                                cout<<"ID of Product 1: ";
                                                cin>>o1;
                                                o1pos=search(phones, no_of_phones, o1);
                                                if (o1pos>=0) {
                                                        cout<<"ID of Product 2: ";
							cin>>o2;
							o2pos=search(phones, no_of_phones, o2);
							if (o2pos>=0) {
								if (o1==o2)
                                                        		cout<<"The IDs are the same."<<endl;
		                                                else {
                		                                        string n1=phones[o1pos].product_name;
                                		                        string n2=phones[o2pos].product_name;
                                                		        int l1=n1.length();
		                                                        int l2=n2.length();
		                                                        if (l1==l2) {
		                                                                int c=1;
		                                                                for (int i=0; i<l1; i++) {
	                	                                                        if (toupper(n1[i]) != toupper(n2[i])) {
        		                                                                        c=0;
	                        	                                                        break;
	                                	                                        }
		                                                                }
                                                		                if (c) {
                                                                		        if (o1<o2) {
		                                                                                phones[o1pos]=phones[o1pos]+phones[o2pos];
		                                                                                no_of_phones--;
		                                                                                cout<<"Products Successfully Combined."<<endl;
		                                                                                cout<<"Product ID: "<<o1<<endl;
                		                                                        } else {
												phones[o2pos]=phones[o1pos]+phones[o2pos];
                                                		                                no_of_phones--;
                                                                		                cout<<"Products Successfully Combined."<<endl;
                                                                                		cout<<"Product ID: "<<o2<<endl;
		                                                                        }		
                		                                                } else
                                		                                        cout<<"Product Names don't match."<<endl;
                                                		        } else
                                                                		cout<<"Product Names don't match."<<endl;
                                                		}	
							} else
								cout<<"Product ID not found."<<endl;
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        } else {
                                                cout<<"ID of Product 1: ";
                                                cin>>o1;
                                                o1pos=search(laptops, no_of_laptops, o1);
                                                if (o1pos>=0) {
                                                        cout<<"ID of Product 2: ";
                                                        cin>>o2;
                                                        o2pos=search(laptops, no_of_laptops, o2);
                                                        if (o2pos>=0) {
                                                                if (o1==o2)
                                                                        cout<<"The IDs are the same."<<endl;
                                                                else {
                                                                        string n1=laptops[o1pos].product_name;
                                                                        string n2=laptops[o2pos].product_name;
                                                                        int l1=n1.length();
                                                                        int l2=n2.length();
                                                                        if (l1==l2) {
                                                                                int c=1;
                                                                                for (int i=0; i<l1; i++) {
                                                                                        if (toupper(n1[i]) != toupper(n2[i])) {
                                                                                                c=0;
                                                                                                break;
                                                                                        }
                                                                                }
                                                                                if (c) {
                                                                                        if (o1<o2) {
                                                                                                laptops[o1pos]=laptops[o1pos]+laptops[o2pos];
                                                                                                no_of_laptops--;
                                                                                                cout<<"Products Successfully Combined."<<endl;
                                                                                                cout<<"Product ID: "<<o1<<endl;
                                                                                        } else {
                                                                                                laptops[o2pos]=laptops[o1pos]+laptops[o2pos];
                                                                                                no_of_laptops--;
                                                                                                cout<<"Products Successfully Combined."<<endl;
                                                                                                cout<<"Product ID: "<<o2<<endl;
                                                                                        }
                                                                                } else
                                                                                        cout<<"Product Names don't match."<<endl;
                                                                        } else
                                                                                cout<<"Product Names don't match."<<endl;
                                                                }
                                                        } else
                                                                cout<<"Product ID not found."<<endl;
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        }
                                } else {
                                        cout<<"Type of Cloth:\n\t1. Shirt\n\t2. Pant"<<endl;
                                        cout<<"Your Choice: ";
                                        cin>>category;
                                        if (category<1 || category>2)
                                                break;
                                        if (category==1) {
						cout<<"ID of Product 1: ";
                                                cin>>o1;
                                                o1pos=search(shirts, no_of_shirts, o1);
                                                if (o1pos>=0) {
                                                        cout<<"ID of Product 2: ";
                                                        cin>>o2;
                                                        o2pos=search(shirts, no_of_shirts, o2);
                                                        if (o2pos>=0) {
                                                                if (o1==o2)
                                                                        cout<<"The IDs are the same."<<endl;
                                                                else {
                                                                        string n1=shirts[o1pos].product_name;
                                                                        string n2=shirts[o2pos].product_name;
                                                                        int l1=n1.length();
                                                                        int l2=n2.length();
                                                                        if (l1==l2) {
                                                                                int c=1;
                                                                                for (int i=0; i<l1; i++) {
                                                                                        if (toupper(n1[i]) != toupper(n2[i])) {
                                                                                                c=0;
                                                                                                break;
                                                                                        }
                                                                                }
                                                                                if (c) {
                                                                                        if (o1<o2) {
                                                                                                shirts[o1pos]=shirts[o1pos]+shirts[o2pos];
                                                                                                no_of_shirts--;
                                                                                                cout<<"Products Successfully Combined."<<endl;
                                                                                                cout<<"Product ID: "<<o1<<endl;
                                                                                        } else {
                                                                                                shirts[o2pos]=shirts[o1pos]+shirts[o2pos];
                                                                                                no_of_shirts--;
                                                                                                cout<<"Products Successfully Combined."<<endl;
                                                                                                cout<<"Product ID: "<<o2<<endl;
                                                                                        }
                                                                                } else
                                                                                        cout<<"Product Names don't match."<<endl;
                                                                        } else
                                                                                cout<<"Product Names don't match."<<endl;
                                                                }
                                                        } else
                                                                cout<<"Product ID not found."<<endl;
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        } else {
						cout<<"ID of Product 1: ";
                                                cin>>o1;
                                                o1pos=search(pants, no_of_pants, o1);
                                                if (o1pos>=0) {
                                                        cout<<"ID of Product 2: ";
                                                        cin>>o2;
                                                        o2pos=search(pants, no_of_pants, o2);
                                                        if (o2pos>=0) {
                                                                if (o1==o2)
                                                                        cout<<"The IDs are the same."<<endl;
                                                                else {
                                                                        string n1=pants[o1pos].product_name;
                                                                        string n2=pants[o2pos].product_name;
                                                                        int l1=n1.length();
                                                                        int l2=n2.length();
                                                                        if (l1==l2) {
                                                                                int c=1;
                                                                                for (int i=0; i<l1; i++) {
                                                                                        if (toupper(n1[i]) != toupper(n2[i])) {
                                                                                                c=0;
                                                                                                break;
                                                                                        }
                                                                                }
                                                                                if (c) {
                                                                                        if (o1<o2) {
                                                                                                pants[o1pos]=pants[o1pos]+pants[o2pos];
                                                                                                no_of_pants--;
                                                                                                cout<<"Products Successfully Combined."<<endl;
                                                                                                cout<<"Product ID: "<<o1<<endl;
                                                                                        } else {
                                                                                                pants[o2pos]=pants[o1pos]+pants[o2pos];
                                                                                                no_of_pants--;
                                                                                                cout<<"Products Successfully Combined."<<endl;
                                                                                                cout<<"Product ID: "<<o2<<endl;
                                                                                        }
                                                                                } else
                                                                                        cout<<"Product Names don't match."<<endl;
                                                                        } else
                                                                                cout<<"Product Names don't match."<<endl;
                                                                }
                                                        } else
                                                                cout<<"Product ID not found."<<endl;
                                                } else
                                                        cout<<"Product ID not found."<<endl;
                                        }
                               	}
				break;
                        case 9:
                                cout<<"\nCustomer Phone Number: ";
                                cin>>cphone;
                                cpos=searchCustomer(customers, no_of_customers, cphone);
                                if (cpos>=0) {
                                        cout<<"Product Category:\n\t1. Gadget\n\t2. Cloth"<<endl;
                                        cout<<"Your Choice: ";
                                        cin>>category;
                                        if (category<1 || category>2)
                                                break;
                                        if (category==1) {
                                                cout<<"Type of Device:\n\t1. Phone\n\t2. Laptop"<<endl;
                                                cout<<"Your Choice: ";
                                                cin>>category;
                                                cout<<"Product ID: ";
                                                cin>>pr_id;
                                                if (category<1 || category>2)
                                                        break;
                                                 if (category==1) {
                                                        ppos=search(phones, no_of_phones, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Phone p = phones[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        phones[ppos].quantity-=qty;
                                                                        Bill b;
                                                                        b.createBill(b_id);
                                                                        b_id++;
                                                                        b.getCustomer(customers[cpos]);
                                                                        b.add(p);
                                                                        cout<<"Bill Created\nBill ID: "<<b.bill_id<<endl;
                                                                        bills[no_of_bills]=b;
                                                                        no_of_bills++;
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                                } else {
                                                        ppos=search(laptops, no_of_laptops, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Laptop p=laptops[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        laptops[ppos].quantity-=qty;
                                                                        Bill b;
                                                                        b.createBill(b_id);
                                                                        b_id++;
                                                                        b.getCustomer(customers[cpos]);
                                                                        b.add(p);
                                                                        cout<<"Bill Created\nBill ID: "<<b.bill_id<<endl;
                                                                        bills[no_of_bills]=b;
                                                                        no_of_bills++;
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                                }
                                        } else {
                                                cout<<"Type of Cloth:\n\t1. Shirt\n\t2. Pant"<<endl;
                                                cout<<"Your Choice: ";
                                                cin>>category;
                                                if (category<1 || category>2)
                                                        break;
                                                cout<<"Product ID: ";
                                                cin>>pr_id;
                                                if (category==1) {
                                                        ppos=search(shirts, no_of_shirts, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Shirt p=shirts[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        shirts[ppos].quantity-=qty;
                                                                        Bill b;
                                                                        b.createBill(b_id);
                                                                        b_id++;
                                                                        b.getCustomer(customers[cpos]);
                                                                        b.add(p);
                                                                        cout<<"Bill Created\nBill ID: "<<b.bill_id<<endl;
                                                                        bills[no_of_bills]=b;
                                                                        no_of_bills++;
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                                } else {
                                                        ppos=search(pants, no_of_pants, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Pant p=pants[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        pants[ppos].quantity-=qty;
                                                                        Bill b;
                                                                        b.createBill(b_id);
                                                                        b_id++;
                                                                        b.getCustomer(customers[cpos]);
                                                                        b.add(p);
                                                                        cout<<"Bill Created\nBill ID: "<<b.bill_id<<endl;
                                                                        bills[no_of_bills]=b;
                                                                        no_of_bills++;
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                                }
                                        }
                                } else
                                        cout<<"Customer not found."<<endl;
                                break;
                        case 10:
                                cout<<"\nBill ID: ";
                                cin>>id;
                                pos=searchBill(bills, no_of_bills, id);
                                if (pos>=0) {
                                        cout<<"Product Category:\n\t1. Gadget\n\t2. Cloth"<<endl;
                                        cout<<"Your Choice: ";
                                        cin>>category;
                                        if (category<1 || category>2)
                                                break;
                                        if (category==1) {
                                                cout<<"Type of Device:\n\t1. Phone\n\t2. Laptop"<<endl;
                                                cout<<"Your Choice: ";
                                                cin>>category;
                                                cout<<"Product ID: ";
                                                cin>>pr_id;
                                                if (category<1 || category>2)
                                                        break;
                                                 if (category==1) {
                                                        ppos=search(phones, no_of_phones, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Phone p = phones[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        phones[ppos].quantity-=qty;
                                                                        bills[pos].add(p);
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                                } else {
                                                        ppos=search(laptops, no_of_laptops, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Laptop p=laptops[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        laptops[ppos].quantity-=qty;
                                                                        bills[pos].add(p);
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                                }
                                        } else {
                                                cout<<"Type of Cloth:\n\t1. Shirt\n\t2. Pant"<<endl;
                                                cout<<"Your Choice: ";
                                                cin>>category;
                                                if (category<1 || category>2)
                                                        break;
                                                cout<<"Product ID: ";
                                                cin>>pr_id;
                                                if (category==1) {
                                                        ppos=search(shirts, no_of_shirts, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Shirt p=shirts[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        shirts[ppos].quantity-=qty;
                                                                        bills[pos].add(p);
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                                } else {
                                                        ppos=search(pants, no_of_pants, pr_id);
                                                        if (ppos>=0) {
                                                                cout<<"Quantity: ";
                                                                cin>>qty;
                                                                Pant p=pants[ppos];
                                                                if (qty<=p.quantity) {
                                                                        p.quantity=qty;
                                                                        pants[ppos].quantity-=qty;
                                                                        bills[pos].add(p);
                                                                } else
                                                                        cout<<"Required quantity of "<<p.product_name<<" is not available."<<endl;
                                                        } else
                                                                cout<<"Product not found."<<endl;
                                              }
                                        }
                                } else
                                        cout<<"Bill ID not found."<<endl;
                                break;
			case 11:
				 cout<<"\nID of Bill 1: ";
                                cin>>o1;
                                o1pos=searchBill(bills, no_of_bills, o1);
                                if (o1pos>=0) {
                                        cout<<"ID of Bill 2: ";
                                        cin>>o2;
                                        o2pos=searchBill(bills, no_of_bills, o2);
                                        if (o2pos>=0) {
                                                if (o1==o2)
                                                        cout<<"The IDs are the same."<<endl;
                                                else {
                                                        string c1=bills[o1pos].customer.phone_no;
                                                        string c2=bills[o2pos].customer.phone_no;
                                                        if (c1==c2) {
                                                                np1=bills[o1pos].no_of_phones;
                                                                np2=bills[o2pos].no_of_phones;
                                                                t1=np1+np2;
                                                                for (int i=0; i<np1; i++)
                                                                        for (int j=0; j<np2; j++)
                                                                                if (bills[o1pos].phones[i].product_id==bills[o2pos].phones[j].product_id)
                                                                                        t1--;
                                                                np1=bills[o1pos].no_of_laptops;
								np2=bills[o2pos].no_of_laptops;
								t2=np1+np2;
								for (int i=0; i<np1; i++)
									for (int j=0; i<np2; j++)
										if (bills[o1pos].laptops[i].product_id==bills[o2pos].laptops[j].product_id)
											t2--;
								np1=bills[o1pos].no_of_shirts;
                                                                np2=bills[o2pos].no_of_shirts;
                                                                t3=np1+np2;
                                                                for (int i=0; i<np1; i++)
                                                                        for (int j=0; i<np2; j++)
                                                                                if (bills[o1pos].shirts[i].product_id==bills[o2pos].shirts[j].product_id)
                                                                                        t3--;
								np1=bills[o1pos].no_of_pants;
                                                                np2=bills[o2pos].no_of_pants;
                                                                t4=np1+np2;
                                                                for (int i=0; i<np1; i++)
                                                                        for (int j=0; i<np2; j++)
                                                                                if (bills[o1pos].pants[i].product_id==bills[o2pos].pants[j].product_id)
                                                                                        t4--;
                                                                if (t1<=3 && t2<=3 && t3<=3 && t4<=3) {
                                                                        if (o1<o2) {
                                                                                bills[o1pos]=bills[o1pos]+bills[o2pos];
										for (int i=o2pos; i<no_of_bills-1; i++)
											bills[i]=bills[i+1];
                                                                                no_of_bills--;
                                                                                cout<<"Bills Successfully Combined."<<endl;
                                                                                cout<<"Bill ID: "<<o1<<endl;
                                                                        } else {
                                                                                bills[o2pos]=bills[o2pos]+bills[o1pos];
										for (int i=o1pos; i<no_of_bills-1; i++)
											bills[i]=bills[i+1];
                                                                                no_of_bills--;
                                                                                cout<<"Bills Successfully Combined."<<endl;
                                                                                cout<<"Bill ID: "<<o2<<endl;
                                                                        }
                                                                } else
                                                                        cout<<"These bills can't be combined as the product count exceeds the assigned limit."<<endl;
                                                        } else
                                                                cout<<"These bills can't be combined as they belong to different customers."<<endl;

                                                }
                                        } else
                                                cout<<"ID not found."<<endl;
                                } else
                                        cout<<"ID not found."<<endl;
				break;
                        case 12:
                                cout<<"\nBill ID: ";
                                cin>>id;
                                pos=searchBill(bills, no_of_bills, id);
                                if (pos>=0)
                                        bills[pos].displayBill();
                                else
                                        cout<<"Bill ID not found."<<endl;
                                break;
                        default:
                                cout<<"Invalid Choice."<<endl;
                                break;
                }
        }
        return 0;
}
