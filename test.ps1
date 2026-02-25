$ImageFilename = "Local\image.ppm"

&fbuild
if ($lastexitcode -ne 0) {
	exit $lastexitcode
}

.\run.ps1
if ($lastexitcode -ne 0) {
	exit $lastexitcode
}

&gimp $ImageFilename