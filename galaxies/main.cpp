#include<iostream>
#include<string>
#include<cmath>
#include<vector>

class Galaxies
{
private:
    std::string hubble_type;
    double redshift;
    double total_mass;
    double stellar_mass_fraction;
    std::vector<Galaxies> satellites; 
public:
    //Default Constructor
    Galaxies() = default;
    //Parametrised Constructor
    Galaxies(std::string type, double z, double M_tot, double frac):
    hubble_type{type}, redshift{z}, total_mass{M_tot}, stellar_mass_fraction{frac}
    {std::cout << "Galaxy Constructed" << std::endl;}
     ~Galaxies(){std::cout<<"Destroying "<<hubble_type<<std::endl;}  // Destructor
     
    void change_hubble_type(std::string new_ht)
    {
        hubble_type = new_ht;
    }

    void add_satelites(Galaxies g_satelite)
    {
        satellites.push_back(g_satelite);
    }    
    double calculate_stellar_mass();
    void print();
    
};

void Galaxies::print()
{
    std::cout << "The Hubble Type: " << hubble_type << std::endl;
    std::cout << "Redshift: " << redshift << std::endl;
    std::cout << "Total Mass: " << total_mass << std::endl;
    std::cout << "Stellar Mass: " << calculate_stellar_mass() << std::endl;
    std::cout << "Number of Satellite Galaxies: " << satellites.size() << std::endl;

    //IF THE SIZE IS BIGGER THAN 0 PRINT THE SATELLITE PROPERTIES
    if(satellites.size() > 0){
        std::vector<Galaxies>::iterator satellite_start{satellites.begin()};
        std::vector<Galaxies>::iterator satellite_end{satellites.end()};
        std::vector<Galaxies>::iterator satellite_iterator;
        
        for(satellite_iterator = satellite_start; satellite_iterator < satellite_end; ++satellite_iterator){
            satellite_iterator->print();
        }
    }
};

double Galaxies::calculate_stellar_mass()
{
    double stellar_mass{stellar_mass_fraction*total_mass};
    std::cout << "The Stellar Mass is: " << stellar_mass << std::endl;
    return stellar_mass;
};

void print_multiple_galaxies(std::vector<Galaxies> &galaxy_data)
{
    std::vector<Galaxies>::iterator galaxy_data_start{galaxy_data.begin()};
    std::vector<Galaxies>::iterator galaxy_data_end{galaxy_data.end()};
    std::vector<Galaxies>::iterator galaxy_data_iterator;
    for(galaxy_data_iterator = galaxy_data_start; galaxy_data_iterator < galaxy_data_end; ++galaxy_data_iterator){
        galaxy_data_iterator -> print();
    }
}

int main()
{
    std::vector<Galaxies> galaxy_data;
    Galaxies gal_1("E0-7", 1, 1e9, 0.4);
    Galaxies gal_2("S0", 2, 1e8, 0.3 );
    Galaxies satelite_1("Sc", 3, 1e7, 0.5);
    gal_1.add_satelites(satelite_1);
    galaxy_data.push_back(gal_1);
    galaxy_data.push_back(gal_2);
    std::cout << "Welcome to the Galaxy OOP Project!!" << std::endl;
    print_multiple_galaxies(galaxy_data);
    return 0;
}
