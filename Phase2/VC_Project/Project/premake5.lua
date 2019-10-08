projectName = "Compiler"

workspace(projectName)
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project(projectName)
	location(projectName)
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		(projectName .. "/**.h"),
		(projectName .. "/**.cpp"),
		(projectName .. "/Scanner.l"),
		(projectName .. "/Parser.y")
	}

	includedirs{
		(projectName .. "/src")
	}
	
	prebuildcommands{
		"del /f lex.yy.cpp",
		"del /f Parser.tab.cpp",
		"flex Scanner.l",
		"bison -d -v Parser.y",
		"rename lex.yy.c lex.yy.cpp",
		"rename Parser.tab.c Parser.tab.cpp"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "TINSLAM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TINSLAM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TINSLAM_DIST"
		runtime "Release"
		optimize "On"

os.execute("mkdir " .. projectName)
os.execute("mkdir " .. projectName .. "\\Inputs")
os.execute("mkdir " .. projectName .. "\\Output")

if(not os.isfile(projectName .. "\\lex.yy.cpp")) then
	os.copyfile("../TinSlam/lex.yy.cpp", (projectName .. "/lex.yy.cpp"))
end

if(not os.isfile(projectName .. "\\Scanner.l")) then
	os.copyfile("../TinSlam/Scanner.l", (projectName .. "/Scanner.l"))
end

if(not os.isfile(projectName .. "\\Parser.tab.cpp")) then
	os.copyfile("../TinSlam/Parser.tab.cpp", (projectName .. "/Parser.tab.cpp"))
end

if(not os.isfile(projectName .. "\\Parser.y")) then
	os.copyfile("../TinSlam/Parser.y", (projectName .. "/Parser.y"))
end

function copyDirectory(src, dst)
	local popen = io.popen
	for filename in popen('dir "' .. src .. '" /b'):lines() do
		if(os.isdir(src .. "\\" .. filename)) then
			os.execute("mkdir " .. dst .. "\\" .. filename)
			copyDirectory(src .. "\\" .. filename, dst .. "\\" .. filename)
		else
			os.copyfile(src .. "\\" .. filename, dst .. "\\" .. filename)
		end
	end
end

copyDirectory("../TinSlam\\Inputs", (projectName .. "\\Inputs"))