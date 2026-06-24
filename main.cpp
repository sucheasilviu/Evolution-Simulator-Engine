#include "Environment.h"
#include "Exceptions.h"
#include "Trait.h"
#include "TraitFactory.h"
#include "SimulationUtils.h"
#include <iostream>

int main() {
    std::cout << "=== Evolution Simulator Engine v3.0 ===\n";


    // instantierei
    MetricsTracker<float> fitnessHistory;
    MetricsTracker<int> populationHistory;

    try {
        Environment earth(0);

        // Folosire Factory Method pentru crearea trasaturilor
        Chromosome adn1;
        adn1.addTrait(TraitFactory::createTrait("Physical", "Putere", 10.5f, 4.2f));
        adn1.addTrait(TraitFactory::createTrait("Behavioral", "Teritorialitate", 5.0f, 8.5f));

        Chromosome adn2;
        adn2.addTrait(TraitFactory::createTrait("Physical", "Viteza", 15.0f, 2.0f));
        adn2.addTrait(TraitFactory::createTrait("Metabolic", "Digestie", 5.0f, 0.8f));

        Organism org1("Adam", adn1);
        Organism org2("Eva", adn2);

        earth.addOrganism(org1);
        earth.addOrganism(org2);

        // Inregistram populatia initiala
        populationHistory.addRecord(Organism::getTotalOrganisms());

        // Demonstrare INSTANTIERE FUNCTIE SABLON
        // Instantierea 1
        float rateDeBaza = 1.5f; // intentionat peste 1.0
        float safeMutationRate = clampValue<float>(rateDeBaza, 0.0f, 1.0f); // Se va plafona la 1.0f

        // Instantierea 2
        int varstaGeneratie = clampValue<int>(150, 0, 100); // Se va plafona la 100

        std::cout << "\nRata de mutatie sigura aplicata: " << safeMutationRate << "\n";
        earth.simulateGeneration(safeMutationRate);

        std::cout << "\n--- Metrici Simulare ---\n";
        populationHistory.printHistory("Dimensiune Populatie");

    }
    catch (const EvolutionException& e) {
        std::cerr << "[Exceptie Evolutie] " << e.what() << "\n";
    }

    return 0;
}