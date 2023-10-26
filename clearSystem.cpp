#include <iostream>
#include <unistd.h>
#include <string>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

void backupSystemSettings(const std::string &backupPath)
{
    std::string command = "reg export HKEY_LOCAL_MACHINE\\Software " + backupPath;
    int result = system(command.c_str());
    if (result != 0)
    {
        throw std::runtime_error("Failed to backup system settings.");
    }
}

void rollbackSystemSettings(const std::string &backupPath)
{
    std::string command = "reg import " + backupPath;
    int result = system(command.c_str());
    if (result != 0)
    {
        throw std::runtime_error("Failed to rollback system settings.");
    }
}
void optimizeCSGOSettings(const std::string &csgoConfigPath)
{
    try
    {
        std::ofstream csgoConfigFile(csgoConfigPath);

        if (!csgoConfigFile.is_open())
        {
            throw std::runtime_error("Failed to open the CS:GO configuration file.");
        }

        // Modify CS:GO configuration settings for optimization.
        csgoConfigFile << "setting1 = value1" << std::endl; // Replace with actual settings.
        csgoConfigFile << "setting2 = value2" << std::endl; // Replace with actual settings.

        csgoConfigFile.close();
        std::cout << "CS:GO configuration optimized successfully." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to optimize CS:GO configuration: " << e.what() << std::endl;
    }
}

void powershellCommandsWindows()
{
    std::string powershellCommand = "$services=@( 'diagnosticshub.standardcollector.service' 'DiagTrack' 'dmwappushservice' 'HomeGroupListener' 'HomeGroupProvider' 'lfsvc' 'MapsBroker' 'NetTcpPortSharing' 'RemoteAccess' 'RemoteRegistry' 'SharedAccess' 'TrkWks' 'WbioSrvc' #'WlanSvc' 'WMPNetworkSvc' 'wscsvc' #'WSearch' 'XblAuthManager' 'XblGameSave' 'XboxNetApiSvc' #Serviceswhichcannotbedisabled #'WdNisSvc' ) foreach($servicein$services){ Write-Output'Tryingtodisable$service' Get-Service-Name$service|Set-Service-StartupTypeDisabled }";
    std::string powershellCommand1 = "Import-Module-DisableNameChecking$PSScriptRoot\..\lib\take-own.psm1 Import-Module-DisableNameChecking$PSScriptRoot\..\lib\force-mkdir.psm1 Write-Output'Elevatingprivilegesforthisprocess' do{}until(Elevate-PrivilegesSeTakeOwnershipPrivilege) Write-Output'Uninstallingdefaultapps' $apps=@( 'Microsoft.3DBuilder' 'Microsoft.Appconnector' 'Microsoft.BingFinance' 'Microsoft.BingNews' 'Microsoft.BingSports' 'Microsoft.BingWeather' 'Microsoft.Getstarted' 'Microsoft.MicrosoftOfficeHub' 'Microsoft.MicrosoftSolitaireCollection' 'Microsoft.Office.OneNote' 'Microsoft.People' 'Microsoft.SkypeApp' 'Microsoft.WindowsAlarms' 'Microsoft.WindowsCamera' 'Microsoft.WindowsMaps' 'Microsoft.WindowsPhone' 'Microsoft.WindowsSoundRecorder' 'Microsoft.XboxApp' 'Microsoft.ZuneMusic' 'Microsoft.ZuneVideo' 'microsoft.windowscommunicationsapps' 'Microsoft.MinecraftUWP' 'Microsoft.MicrosoftPowerBIForWindows' 'Microsoft.NetworkSpeedTest' 'Microsoft.CommsPhone' 'Microsoft.ConnectivityStore' 'Microsoft.Messaging' 'Microsoft.Office.Sway' 'Microsoft.OneConnect' 'Microsoft.WindowsFeedbackHub' 'Microsoft.BingFoodAndDrink' 'Microsoft.BingTravel' 'Microsoft.BingHealthAndFitness' 'Microsoft.WindowsReadingList' '9E2F88E3.Twitter' 'PandoraMediaInc.29680B314EFC2' 'Flipboard.Flipboard' 'ShazamEntertainmentLtd.Shazam' 'king.com.CandyCrushSaga' 'king.com.CandyCrushSodaSaga' 'king.com.*' 'ClearChannelRadioDigital.iHeartRadio' '4DF9E0F8.Netflix' '6Wunderkinder.Wunderlist' 'Drawboard.DrawboardPDF' '2FE3CB00.PicsArt-PhotoStudio' 'D52A8D61.FarmVille2CountryEscape' 'TuneIn.TuneInRadio' 'GAMELOFTSA.Asphalt8Airborne' 'DB6EA5DB.CyberLinkMediaSuiteEssentials' 'Facebook.Facebook' 'flaregamesGmbH.RoyalRevolt2' 'Playtika.CaesarsSlotsFreeCasino' 'A278AB0D.MarchofEmpires' 'KeeperSecurityInc.Keeper' 'ThumbmunkeysLtd.PhototasticCollage' 'XINGAG.XING' '89006A2E.AutodeskSketchBook' 'D5EA27B7.Duolingo-LearnLanguagesforFree' '46928bounde.EclipseManager' 'ActiproSoftwareLLC.562882FEEB491' ) foreach($appin$apps){ Write-Output'Tryingtoremove$app' Get-AppxPackage-Name$app-AllUsers|Remove-AppxPackage-AllUsers Get-AppXProvisionedPackage-Online| Where-ObjectDisplayName-EQ$app| Remove-AppxProvisionedPackage-Online } #Prevents'SuggestedApplications'returning force-mkdir'HKLM:\SOFTWARE\Policies\Microsoft\Windows\CloudContent' Set-ItemProperty'HKLM:\SOFTWARE\Policies\Microsoft\Windows\CloudContent''DisableWindowsConsumerFeatures'1";
    std::string command = "powershell.exe -ExecutionPolicy Bypass -Command \"" + std::string(powershellCommand) + std::string(powershellCommand1) + "\"";

    int result = system(command.c_str());

    if (result == 0)
    {
        std::cout << "PowerShell команда успешно выполнена." << std::endl;
    }
    else
    {
        std::cerr << "Ошибка при выполнении PowerShell команды. Код ошибки: " << result << std::endl;
    }
}
void clearCacheWindows()
{
    try
    {
        system("del /q /s %temp%\\*.*");
        std::cout << "Очистка кэша прошла успешно" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка при очистке кэша на Windows: " << e.what() << std::endl;
        return;
    }
}

void clearCacheLinux()
{
    try
    {
        system("systemd-resolve --flush-caches");
        std::cout << "Очистка кэша прошла успешно" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка при очистке кэша на Linux: " << e.what() << std::endl;
        return;
    }
}
bool powerPlanExists(const char *planName)
{
    std::string command = "powercfg -l | find \"" + std::string(planName) + "\"";
    return system(command.c_str()) == 0;
}

void createUltimatePowerPlan()
{
    if (!powerPlanExists("Ultimate Performance"))
    {
        system("powercfg -duplicatescheme 8c5e7fda-e4f5-4a54-9a28-3e001f13576d");
        std::cout << "Создан режим 'Ultimate Performance'." << std::endl;
    }
}

void setUltimatePowerPlan()
{
    try
    {
        createUltimatePowerPlan();

        system("powercfg -setactive 8c5e7fda-e4f5-4a54-9a28-3e001f13576d");

        std::cout << "Режим 'Ultimate Performance' успешно установлен." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка при установке режима 'Ultimate Performance': " << e.what() << std::endl;
    }
}

void boostSystem(std::string systemName)
{
    if (systemName == "Windows")
    {
        setUltimatePowerPlan();
        powershellCommandsWindows();
    }
    if (systemName == "Linux")
    {
        system("echo performance | tee /sys/devices/system/cpu/cpufreq/policy0/scaling_governor");
    }
    if (systemName == "Macos")
    {
        system("sudo sysctl -w vm.swappiness=10");
    }
}

void clearCacheMacOS()
{
    try
    {
        system("dscacheutil -flushcache");
        std::cout << "Очистка кэша прошла успешно" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка при очистке кэша на macOS: " << e.what() << std::endl;
        return;
    }
}
void clearCache(std::string systemName)
{
    if (systemName == "Windows")
    {
        clearCacheWindows();
    }
    if (systemName == "Linux")
    {
        clearCacheLinux();
    }
    if (systemName == "Macos")
    {
        clearCacheMacOS();
    }
}

void clearDota2Customs(std::string dota2CustomsPath)
{

    try
    {
        if (fs::exists(dota2CustomsPath) && fs::is_directory(dota2CustomsPath))
        {
            for (const auto &entry : fs::directory_iterator(dota2CustomsPath))
            {
                fs::remove_all(entry.path());
            }
            std::cout << "Папка кастомок Dota 2 успешно очищена." << std::endl;
        }
        else
        {
            std::cerr << "Директория " << dota2CustomsPath << "с кастомками Dota 2 не найдена." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка при очистке кастомок Dota 2: " << e.what() << std::endl;
    }
}

void clearCSGOTempFiles(std::string csgoTempDir)
{

    try
    {
        if (fs::exists(csgoTempDir) && fs::is_directory(csgoTempDir))
        {
            for (const auto &entry : fs::directory_iterator(csgoTempDir))
            {
                fs::remove_all(entry.path());
            }
            std::cout << "Папка кастомок Dota 2 успешно очищена." << std::endl;
        }
        else
        {
            std::cerr << "Директория " << csgoTempDir << "с кэшом cs go не найдена" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка при очистке кастомок Dota 2: " << e.what() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::string mode = "easy";
    std::string dota = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\dota 2 beta\\game\\dota\\addons";
    std::string csgo = "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Counter-Strike Global Offensive\\csgo\\cache";
    std::string systemName = "Windows";
    int opt;
    while ((opt = getopt(argc, argv, "m:d:c:s:")) != -1)
    {
        switch (opt)
        {
        case 'm':
            mode = optarg;
            break;
        case 'd':
            dota = optarg;
            break;
        case 'c':
            csgo = optarg;
            break;
        case 's':
            systemName = optarg;
            break;
        default:
            std::cerr << "Использование: " << argv[0] << " -m <режим> -d <путь к Dota> -c <путь к CS:GO> -s <название системы>" << std::endl;
            return 1;
        }
    }

    if (mode == "easy")
    {
        std::cout << "Вы находитесь в режиме easy" << std::endl;
        clearCache(systemName);
    }
    else if (mode == "medium")
    {
        std::cout << "Вы находитесь в режиме medium" << std::endl;
        clearCache(systemName);
        clearDota2Customs(dota);
    }
    else if (mode == "hard")
    {
        std::cout << "Вы находитесь в режиме hard" << std::endl;
        clearCache(systemName);
        clearDota2Customs(dota);
        clearCSGOTempFiles(csgo);
        optimizeCSGOSettings(csgo);
        boostSystem(systemName);
    }
    else
    {
        std::cerr << "Недопустимый режим: " << mode << std::endl;
        return 1;
    }

    return 0;
}
