$RunTimeSpan = Measure-Command {
	&".\Build\x64_Debug\FikaRay.exe" > $ImageFilename
}
Write-Host "$($RunTimeSpan.TotalMilliseconds)ms $($RunTimeSpan.Ticks)ticks"

exit $lastexitcode