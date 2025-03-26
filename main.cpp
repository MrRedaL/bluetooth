#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    // Exécution de la commande pour obtenir la vitesse Wi-Fi
    std::string command = "iw dev wlan0 link | grep -oP 'tx bitrate: \K[^\n]+'";
    char buffer[128];
    std::string result = "";

    FILE* fp = popen(command.c_str(), "r");
    if (fp == nullptr) {
        std::cerr << "Erreur lors de l'exécution de la commande" << std::endl;
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
        result += buffer;
    }

    fclose(fp);
    
    // Affichage du débit
    std::cout << "Débit Wi-Fi : " << result << std::endl;

    return 0;
}
