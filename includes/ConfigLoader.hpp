//
// Created by sufyan kerboua on 16/07/2020.
//

#pragma once

#include <yaml-cpp/yaml.h>

class ConfigLoader : public YAML::Node
{
public:
    ConfigLoader(const std::string &filePath) : YAML::Node(YAML::LoadFile(filePath)) {};
    ~ConfigLoader() = default;

    inline std::string getFilePath() { return _filePath; }

private:
    const std::string _filePath;
};
