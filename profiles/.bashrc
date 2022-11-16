# soucre ~/.bashrc to update changes

# Navigation:
alias me="cd ~/"
alias me.code="cd ~/bin/code"
alias me.profiles="cd ~/bin/code/working_knowledge/profiles; echo \"Run './update_profile.sh' to update changes.\""
# alias me.edit.settings="cd ~/bin/code/working_knowledge/profile; code .; echo \"Run .update_profile.sh script.\""

# Utility:
alias la="ls -lra"
alias source.bashrc="source ~/.bashrc"

# Settings
alias python="python3"

# TIME: \[\e[31m\]\D{%c}\[\e[0m\]
# USER: [\[\e[1;43m\]\u\[\e[0m\]@\H]
PS1="\[\e[36m\]\w\[\e[0m\]$ "
