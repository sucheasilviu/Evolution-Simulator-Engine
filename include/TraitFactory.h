#pragma once
#include "Trait.h"
#include <memory>
#include <string>
#include <stdexcept>

class TraitFactory {
public:
    // Factory Method pentru a crea instante concrete de Trait
    static std::unique_ptr<Trait> createTrait(const std::string& type, const std::string& name, float baseVal, float specificVal) {
        if (type == "Physical") return std::make_unique<PhysicalTrait>(name, baseVal, specificVal);
        if (type == "Sensory") return std::make_unique<SensoryTrait>(name, baseVal, specificVal);
        if (type == "Metabolic") return std::make_unique<MetabolicTrait>(name, baseVal, specificVal);
        if (type == "Behavioral") return std::make_unique<BehavioralTrait>(name, baseVal, specificVal);

        throw std::invalid_argument("Eroare: Tip de trasatura necunoscut!");
    }
};