-- Definir el proyecto
workspace "MemoryAllocators"
    configurations { "Debug", "Release" }

function addIncludeDirs(baseDir)
    local dirs = os.matchdirs(baseDir .. "/**")

    includedirs { baseDir }
    for _, dir in ipairs(dirs) do
        if os.isdir(dir) then
            if not dir:match("c++") and not dir:match("isl$") and not dir:match("FLAC$") then
                includedirs { dir }
            elseif dir:match("15.2.0$") or dir:match("bits$") then
                includedirs { dir }
            end
        end
    end
end

function addHeaderFiles(baseDir)
    local hFiles = os.matchfiles(baseDir .. "/**.h")
    local hppFiles = os.matchfiles(baseDir .. "/**.hpp")
    
    for _, file in ipairs(hFiles) do
        files { file }
    end
    for _, file in ipairs(hppFiles) do
        files { file }
    end
end

function addSrcFiles(baseDir)
    local cFiles = os.matchfiles(baseDir .. "/**.c")
    local cppFiles = os.matchfiles(baseDir .. "/**.cpp")
    
    for _, file in ipairs(cFiles) do
        files { file }
    end
    for _, file in ipairs(cppFiles) do
        files { file }
    end
end

-- Definir el proyecto en sí
project "MemoryAllocatorsCore"
    kind "ConsoleApp"  -- Tipo de proyecto: aplicación de consola
    language "C++"
    buildoptions { "-std=c++20" }
    targetdir "bin/%{cfg.buildcfg}"  -- Donde se guardarán los archivos ejecutables

    print("Working Dir : " .. _WORKING_DIR )

    addSrcFiles("src")
    addHeaderFiles("include/")

    addIncludeDirs("include/")

    includedirs("C:/msys64/mingw64/include")
    includedirs("C:/msys64/mingw64/include/c++/15.2.0")

    files {
        "external/imgui/imgui.cpp",           -- Núcleo de ImGui
        "external/imgui/imgui_draw.cpp",      -- Dibujo de la interfaz
        "external/imgui/imgui_widgets.cpp",   -- Widgets básicos
        "external/imgui/imgui_tables.cpp",    -- Manejo de tablas
        "external/imgui/backends/imgui_impl_glfw.cpp", -- Integración con GLFW
        "external/imgui/backends/imgui_impl_opengl3.cpp" -- Integración con OpenGL
    }
    files
    {
        "C:/libs/glad/src/glad.c"
    }


    includedirs { "external/imgui" }

    includedirs { "C:/libs/glad/include" }
    includedirs { "C:/libs/glfw3/include" }

    libdirs { "C:/libs/glfw3/lib-mingw-w64" }
    libdirs { "C:/msys64/mingw64/lib" }

    filter "system:Windows"
        links { "freetype", "glfw3", "opengl32", "glu32", "gdi32" }

    -- Configuraciones específicas para los builds
    filter "configurations:Debug"
        buildoptions { "-DDEBUG", "-DNDEBUG" }
        symbols "On"  -- Habilitar símbolos de depuración
        optimize "Off"  -- No optimizar en Debug
        targetsuffix "_Debug" -- Añadir un sufijo _debug al nombre del ejecutable
        includedirs("C:/msys64/mingw64/include/gdb")


    filter "configurations:Release"
        buildoptions { "-DRELEASE" }
        optimize "On"  -- Optimizar en Release
        symbols "Off"  -- Desactivar símbolos de depuración
        targetsuffix "_Release" -- Añadir un sufijo _release al nombre del ejecutable

newaction {
   trigger = "Clean",
   description = "Clean the project build",
   execute = function ()
      print("Cleaning project...")

      os.rmdir("bin")
      os.rmdir("build")
      os.rmdir("obj")
   end
}