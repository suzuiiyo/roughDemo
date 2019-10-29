# 2019/10/9

# explorer (rvpa $HOME\.vscode\extensions\formulahendry.code-runner*)
# notepad.exe (rvpa $HOME\.vscode\extensions\formulahendry.code-runner*\out\src\codeManager.js)

$addCode = @"
            else if (windowsShell && windowsShell.toLowerCase().indexOf("wsl") > -1) {
                // 修复不能识别 wsl.exe 终端的问题
                command = command.replace(/([A-Za-z]):/g, this.replacer).replace(/\\/g,"/")
            }
"@

Push-Location
$Path = "$(Resolve-Path $HOME\.vscode\extensions\formulahendry.code-runner*)\out\src"
Set-Location $Path


$rawCode = Get-Content .\codeManager.js -Raw -Encoding UTF8
# 备份与覆盖
if (!(Test-Path .\codeManager.js.bak)) {
    Copy-Item -Path .\codeManager.js -Destination .\codeManager.js.bak
}
elseif ($rawCode -match '"wsl"') {
    Copy-Item -Path .\codeManager.js.bak -Destination .\codeManager.js
    Pop-Location
    &$MyInvocation.MyCommand.Definition
    return
}

# 添加对应代码
if ($rawCode -match '(?<old>(?s)changeFilePathForBashOnWindows.*})(?<bash>(?s).*else\sif.*return command;)') {
    $rawCode.Replace($Matches[0], $($Matches.old + $addCode + $Matches.bash)) |
        Out-File .\codeManager.js -Encoding utf8
    Write-Output "[INFO] 成功向 $Path\codeManager.js 中添加 wsl.exe"
}
else {
    Write-Output "[INFO] 未在 $Path\codeManager.js 检索到对应字符串"
}

Pop-Location
"按任意键退出"; $null = [Console]::ReadKey()