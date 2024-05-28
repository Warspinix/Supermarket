#include <iostream>
#include <string>
using namespace std;

class Customer {
        public:
                string phone_no;
                string name;
                string temp;
                int isValid(string pno) {
                        if (pno.length()!=10) {
                                cout<<"Invalid Phone Number."<<endl;
                                return 0;
                        }
                        return 1;
                }
                int getCustomerDetails() {
                        getline(cin, temp);
                        cout<<"\nPhone Number: ";
                        getline(cin, phone_no);
                        if (isValid(phone_no)) {
                                cout<<"Name: ";
                                getline(cin, name);
                                return 1;
                        }
                        return 0;
                }
                int updatePhoneNo (string newno) {
                        if (isValid(newno)) {
                                phone_no=newno;
                                return 1;
                        }
                        return 0;
                }
                void updateName (string newname) {
                        name=newname;
                }
                void displayCustomerDetails() {
                        cout<<"\nPhone No: "<<phone_no<<endl;
                        cout<<"Customer Name: "<<name<<endl;
                }
};

class Product {
        public:
                int product_id, quantity;
                float price;
                string product_name;
                void getProductDetails (int id, float p, string name, int q) {
                        product_id=id;
                        product_name=name;
                        price=p;
                        quantity=q;
                }
                void update (string newname) {
                        cout<<"\nOld Name: "<<product_name<<endl;
                        product_name=newname;
                        cout<<"Product Name successfully updated."<<endl;
                        cout<<"New Name: "<<product_name<<endl;
                }
                void update (float p) {
                        cout<<"\nOld Price = "<<price<<endl;
                        price=p;
                        cout<<"Price of "<<product_name<<" successfully updated."<<endl;
                        cout<<"New Price = "<<price<<endl;
                }
                void update (int q) {
                        cout<<"\nOld Quantity = "<<quantity<<endl;
                        quantity+=q;
                        cout<<"Quantity of "<<product_name<<" successfully updated."<<endl;
                        cout<<"New Quantity = "<<quantity<<endl;
                }
                void displayProductDetails() {
                        cout<<"\nProduct Name: "<<product_name<<endl;
                        cout<<"Price: "<<price<<endl;
                        cout<<"Available Quantity: "<<quantity<<endl;
                }
};

class Gadget: public Product {
        public:
                string brand, display;
                int battery;
                void getGadgetDetails(string b, string d, int bat) {
                        brand=b;
                        display=d;
                        battery=bat;
                }
                void displayGadgetDetails() {
                        cout<<"Brand: "<<brand<<endl;
                        cout<<"Display Technology: "<<display<<endl;
                        cout<<"Battery Capacity: "<<battery<<endl;
                }
};

class Phone: public Gadget {
        public:
                int cameras, unlock;
                string connection;
                void getPhoneDetails(int c, int u, string con) {
                        cameras=c;
                        unlock=u;
                        connection=con;
                }
		Phone operator + (Phone const &p) {
                        Phone result;
                        result.product_id=product_id;
                        result.quantity=quantity+p.quantity;
                        result.price=price;
                        result.product_name=product_name;
                        result.brand=brand;
                        result.display=display;
                        result.battery=battery;
                        result.cameras=cameras;
                        result.unlock=unlock;
                        result.connection=connection;
                        return result;
                }
                void displayPhoneDetails() {
                        cout<<"No. of Cameras: "<<cameras<<endl;
                        cout<<"No. of Unlock Methods: "<<unlock<<endl;
                        cout<<"Connection: "<<connection<<endl;
                }
};

class Laptop: public Gadget {
        public:
                string fans, trackpad, keyboard;
                void getLaptopDetails(string f, string t, string k) {
                        fans=f;
                        trackpad=t;
                        keyboard=k;
                }
		Laptop operator + (Laptop const &p) {
			Laptop result;
			result.product_id=product_id;
                        result.quantity=quantity+p.quantity;
                        result.price=price;
                        result.product_name=product_name;
			result.brand=brand;
                        result.display=display;
                        result.battery=battery;
			result.fans=fans;
			result.trackpad=trackpad;
			result.keyboard=keyboard;
			return result;
		}	
                void displayLaptopDetails() {
                        cout<<"Fans: "<<fans<<endl;
                        cout<<"Trackpad: "<<trackpad<<endl;
                        cout<<"Keyboard: "<<keyboard<<endl;
                }
};

class Clothes: public Product {
        public:
                string material, type;
                float size;
                void getClothDetails (string m, string t, float s) {
                        material=m;
                        type=t;
                        size=s;
                }
                void displayClothDetails () {
                        cout<<"Material: "<<material<<endl;
                        cout<<"Type: "<<type<<endl;
                        cout<<"Cloth Size: "<<size<<endl;
                }
};

class Shirt: public Clothes {
        public:
                string buttons, length;
                void getShirtDetails(string b, string l) {
                        buttons=b;
                        length=l;
                }
		Shirt operator + (Shirt const &p) {
			Shirt result;
			result.product_id=product_id;
                        result.quantity=quantity+p.quantity;
                        result.price=price;
                        result.product_name=product_name;
			result.material=material;
			result.type=type;
			result.size=size;
			result.buttons=buttons;
			result.length=length;
			return result;
		}
                void displayShirtDetails() {
                        cout<<"Button Type: "<<buttons<<endl;
                        cout<<"Arm-Length: "<<length<<endl;
                }
};

class Pant: public Clothes {
        public:
                int pockets;
                string button;
                void getPantDetails(int p, string b) {
                        pockets=p;
                        button=b;
                }
		Pant operator + (Pant const &p) {
			Pant result;
			result.product_id=product_id;
                        result.quantity=quantity+p.quantity;
                        result.price=price;
                        result.product_name=product_name;
                        result.material=material;
                        result.type=type;
                        result.size=size;
			result.pockets=pockets;
			result.button=button;
			return result;
		}
                void displayPantDetails() {
                        cout<<"No. of Pockets: "<<pockets<<endl;
                        cout<<"Pant Button Type: "<<button<<endl;
                }

};

class Cart {
        public:
                Phone * phones=new Phone[3];
                Laptop * laptops=new Laptop[3];
                Shirt * shirts=new Shirt[3];
                Pant* pants=new Pant[3];
                int no_of_phones, no_of_laptops;
                int no_of_shirts, no_of_pants;
                template <typename T>
		int check (T p) {
			int total;
			T * products;
			if constexpr (is_same<T, Phone>::value) {
				total=no_of_phones;
				products=phones;
			} else if constexpr (is_same<T, Laptop>::value) {
				total=no_of_laptops;
				products=laptops;
			} else if constexpr (is_same<T, Shirt>::value) {
				total=no_of_shirts;
				products=shirts;
			} else if constexpr (is_same<T, Pant>::value) {
				total=no_of_pants;
				products=pants;
			}
			for (int i=0; i<total; i++)
				if (products[i].product_id==p.product_id)
					return i;
			return -1;
		}

		template <typename T>
		void add (T p) {
			int pos=check(p);
			if constexpr (is_same<T, Phone>::value) {
				if (pos>=0) {
					phones[pos].quantity+=p.quantity;
				        cout<<p.product_name<<" already exists. "<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				} else {
				        phones[no_of_phones]=p;
				        cout<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				        no_of_phones++;
				}
			} else if constexpr (is_same<T, Laptop>::value) {
				if (pos>=0) {
					laptops[pos].quantity+=p.quantity;
				        cout<<p.product_name<<" already exists. "<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				} else {
				        laptops[no_of_laptops]=p;
				        cout<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				        no_of_laptops++;
				}

			} else if constexpr (is_same<T, Shirt>::value) {
				if (pos>=0) {
					shirts[pos].quantity+=p.quantity;
				        cout<<p.product_name<<" already exists. "<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				} else {
				        shirts[no_of_shirts]=p;
				        cout<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				        no_of_shirts++;
				}

			} else if constexpr (is_same<T, Pant>::value) {
				if (pos>=0) {
					pants[pos].quantity+=p.quantity;
				        cout<<p.product_name<<" already exists. "<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				} else {
				        pants[no_of_pants]=p;
				        cout<<p.quantity<<" units of "<<p.product_name<<" has been added."<<endl;
				        no_of_pants++;
				}
			}
		}            
};

class Bill: public Cart {
        public:
                int bill_id;
                Customer customer;
                float total;
                void createBill (int id) {
                        bill_id=id;
                        no_of_phones=0;
                        no_of_laptops=0;
                        no_of_shirts=0;
                        no_of_pants=0;
                }
                void getCustomer(Customer c) {
                        customer=c;
                }
		Bill operator + (Bill const &b) {
			Bill result;
			for (int i=0; i<no_of_phones; i++) {
				int c=1;
				for (int j=0; j<no_of_phones; j++) {
					if (phones[j].product_id==b.phones[i].product_id) {
						phones[j].quantity+=b.phones[i].quantity;
						c=0;
						break;
					}
				}
				if (c) {
					phones[no_of_phones]=b.phones[i];
					no_of_phones++;
				}
			}
			for (int i=0; i<no_of_laptops; i++) {
                                int c=1;
                                for (int j=0; j<no_of_laptops; j++) {
                                        if (laptops[j].product_id==b.laptops[i].product_id) {
                                                laptops[j].quantity+=b.laptops[i].quantity;
                                                c=0;
                                                break;
					}
                                }
                                if (c) {
                                        laptops[no_of_laptops]=b.laptops[i];
                                        no_of_laptops++;
                                }
                        }
			for (int i=0; i<no_of_shirts; i++) {
                                int c=1;
                                for (int j=0; j<no_of_shirts; j++) {
                                        if (shirts[j].product_id==b.shirts[i].product_id) {
                                                shirts[j].quantity+=b.shirts[i].quantity;
                                                c=0;
                                                break;
					}
                                }
                                if (c) {
                                        shirts[no_of_shirts]=b.shirts[i];
                                        no_of_shirts++;
                                }
                        }
			for (int i=0; i<no_of_pants; i++) {
                                int c=1;
                                for (int j=0; j<no_of_pants; j++) {
                                        if (pants[j].product_id==b.pants[i].product_id) {
                                                pants[j].quantity+=b.pants[i].quantity;
                                                c=0;
                                                break;
					}
                                }
                                if (c) {
                                        pants[no_of_pants]=b.pants[i];
                                        no_of_pants++;
                                }
                        }
			result.bill_id=bill_id;
			result.customer=customer;
			result.phones=phones;
			result.no_of_phones=no_of_phones;
			result.laptops=laptops;
			result.no_of_laptops=no_of_laptops;
			result.shirts=shirts;
			result.no_of_shirts=no_of_shirts;
			result.pants=pants;
			result.no_of_pants=no_of_pants;
			return result;
		}
                void computeTotal() {
                        total=0;
                        for (int i=0; i<no_of_phones; i++)
                                total+=(phones[i].price*phones[i].quantity);
                        for (int i=0; i<no_of_laptops; i++)
                                total+=(laptops[i].price*laptops[i].quantity);
                        for (int i=0; i<no_of_shirts; i++)
                                total+=(shirts[i].price*shirts[i].quantity);
                        for (int i=0; i<no_of_pants; i++)
                                total+=(pants[i].price*pants[i].quantity);
                }
                void displayBill() {
			string name;
                        computeTotal();
                        cout<<"\nCustomer Phone No: "<<customer.phone_no<<endl;
                        cout<<"Customer Name: "<<customer.name<<endl;
                        cout<<"\n|No.\t|Product Name\t|Unit Price\t|Quantity\t|Total Price\t|"<<endl;
			int i, j, k, l;
                        for (i=0; i<no_of_phones; i++) {
                                cout<<"|"<<i+1<<"\t|";
				name=phones[i].product_name;
				if (name.length()<7)
					cout<<name<<"\t\t|";
				else
					cout<<name.substr(0, 11)<<"...\t|";
				cout<<phones[i].price<<"\t\t|";
				cout<<phones[i].quantity<<"\t\t|";
				cout<<phones[i].price*phones[i].quantity<<"\t\t|"<<endl;
                        }
                        for (j=0; j<no_of_laptops; j++) {
                                cout<<"|"<<i+j+1<<"\t|";
				name=laptops[j].product_name;
				if (name.length()<7)
                                        cout<<name<<"\t\t|";
                                else
                                        cout<<name.substr(0, 11)<<"...\t|";
				cout<<laptops[j].price<<"\t\t|";
				cout<<laptops[j].quantity<<"\t\t|";
				cout<<laptops[j].price*laptops[j].quantity<<"\t\t|"<<endl;
                        }
                        for (k=0; k<no_of_shirts; k++) {
                                cout<<"|"<<i+j+k+1<<"\t|";
				name=shirts[k].product_name;
				if (name.length()<7)
                                        cout<<name<<"\t\t|";
                                else
                                        cout<<name.substr(0, 11)<<"...\t|";
				cout<<shirts[k].price<<"\t\t|";
				cout<<shirts[k].quantity<<"\t\t|";
				cout<<shirts[k].price*shirts[k].quantity<<"\t\t|"<<endl;
                        }
                        for (l=0; l<no_of_pants; l++) {
                                cout<<"|"<<i+j+k+l+1<<"\t|";
				name=pants[l].product_name;
				if (name.length()<7)
                                        cout<<name<<"\t\t|";
                                else
                                        cout<<name.substr(0, 11)<<"...\t|";
				cout<<pants[l].price<<"\t\t|";
				cout<<pants[l].quantity<<"\t\t|";
				cout<<pants[l].price*pants[l].quantity<<"\t\t|"<<endl;
                        }
                        cout<<"\nTotal Amount = "<<total<<endl;
                }
};

int searchCustomer (Customer * cs, int total, string p_no) {
        for (int i=0; i<total; i++) {
                if (cs[i].phone_no==p_no)
                        return i;
        }
        return -1;
}

template <typename T>
int search (T * products, int total, int p_id) {
	for (int i=0; i<total; i++)
		if (products[i].product_id==p_id)
			return i;
	return -1;
}

int searchBill (Bill * bs, int total, int b_id) {
        for (int i=0; i<total; i++)
                if (bs[i].bill_id==b_id)
                        return i;
        return -1;
}
