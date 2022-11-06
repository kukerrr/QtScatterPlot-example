C:\Qt6\6.2.2\msvc2019_64\bin\windeployqt.exe x64\Release --release --force


mkdir "Release"
copy x64\Release\QtScatterPlot.exe "Release\QtScatterPlot.exe"

copy qt\D3Dcompiler_47.dll "Release\D3Dcompiler_47.dll"
copy qt\libGLESV2.dll 		"Release\libGLESV2.dll"
copy qt\opengl32sw.dll 		"Release\opengl32sw.dll"
copy qt\Qt6Core.dll 		"Release\Qt6Core.dll"
copy qt\Qt6Gui.dll 			"Release\Qt6Gui.dll"
copy qt\Qt6Charts.dll 		"Release\Qt6Charts.dll"

#RCEDIT.exe /I "Release\QtScatterPlot.exe" "Icons/icon.ico"