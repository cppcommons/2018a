git config --system core.autoCRLF false
git config --system user.name  root
git config --system user.email root@super-computer
git config --unset-all credential.helper
git config --system --unset-all credential.helper
git config --system credential.helper manager
git config --system credential.useHttpPath true
pause
