workspace "Datalyser"
  configurations { "Debug" }
	targetdir ("bin/%{prj.name}/%{cfg.longname}")
	objdir ("obj/%{prj.name}/%{cfg.longname}")
    architecture "x86_64"
    targetdir "bin/Debug"
    language "C++"
    location "."

project "Tables"
    kind "SharedLib"
    files "Tables/**.cpp"
    includedirs "Tables"
    
project "Datalyser"
    kind "SharedLib"
    files "Datalyser/**.cpp"
    includedirs "Datalyser"

project "Test"
    kind "ConsoleApp"
    files "Test/**.cpp"
    includedirs {"Test", "Tables", "Datalyser"}
	links {"Tables", "Datalyser"}
