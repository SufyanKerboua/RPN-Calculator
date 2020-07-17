//
// Created by sufyan kerboua on 14/07/2020.
//

#include "Core.hpp"

static std::map<std::string, std::function<void(void)>> COMMANDS;

static const std::string configFilePath("./config.yml");

/**
 * @brief Constructeur, initialisation de la classe.
   @param None
   */
Core::Core() : _running(true), _language("french"), _config(configFilePath), _commandMap(COMMANDS)
{
    this->setCommands();
}

/**
 * @brief Fonction ayant pour but de mapper chaque commande disponible, avec une lambda
   @param None
   @return void
   */
void Core::setCommands()
{
    _commandMap.emplace("clear", [&](void) -> void {
        std::system("clear");
        _rpnProcessor.clearStack();
    });

    _commandMap.emplace("quit", [&](void) -> void { _running = false; });

    _commandMap.emplace("help", [&](void) -> void {
        std::cout << _config[_language.c_str()]["help"].as<std::string>() << std::endl;
    });

    _commandMap.emplace("language", [&](void) -> void {
        if (_language.compare(_config["languages"]["french"].as<std::string>()) == 0)
            _language = _config["languages"]["english"].as<std::string>();
        else
            _language = _config["languages"]["french"].as<std::string>();
        std::cout << _config[_language.c_str()]["language_switched"].as<std::string>() << std::endl;
    });

}

/**
 * @brief Fonction ayant pour but de récupérer la derniere ligne que l'utilisateur à pu taper
   @param None
   @return void
   */
void Core::getNextLine()
{
    getline(std::cin, _line);
    _tools.removeUnnecessarySpace((std::string &) _line);
}

/**
 * @brief Fonction ayant pour but d'afficher toutes les erreurs que l'utilisateur pourrais avoir commis, selon une
   @param None
   @return void
   */
void Core::printErrorMessage()
{
    if (_tools.getErrorToken().compare("none") != 0)
        std::cout << _config[_language.c_str()]["error"][_tools.getErrorToken().c_str()] << std::endl;
}

/**
 * @brief Fonction ayant pour but de gérer l'expression dans la calculatrice
   @param None
   @return void
   */
void Core::processNewLine()
{
    if (_tools.isOperandOrOperator(_line)) {

        _tools.setErrorToken(_rpnProcessor.setInput(_line));
        this->printErrorMessage();

    } else if (this->isCommand(_line)) {
        this->executeCommands(_line);
    } else
        std::cout << _config[_language.c_str()]["error"]["bad_syntax"] << std::endl;
}

/**
 * @brief Fonction ayant pour but de checker si "param" est une commande ou non
   @param const std::string &param | string à traiter
   @return Bool | return true, si la commande existe, false si la commande n'existe pas
   */
bool Core::isCommand(const std::string &param)
{
    if (_commandMap.find(param) != _commandMap.end())
        return true;
    return false;
}

/**
 * @brief Fonction ayant pour but de lancer la calculatrice
   @param None
   @return void
   */
void Core::run()
{
    this->executeCommands("clear");
    while (_running) {
        std::cout << _config["prompt"].as<std::string>();
        this->getNextLine();
        this->processNewLine();
    }
}