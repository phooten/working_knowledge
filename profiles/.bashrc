# soucre ~/.bashrc to update changes



# ALIAS
    # Navigation:
    alias me="cd ~/"
    alias mecode="cd ~/bin/code"
    alias meprofiles="cd ~/bin/code/working_knowledge/profiles; echo \"Run './update_profile.sh', then 'sbash' to update changes.\""

    # Utility:
    alias la="ls -lra"
    alias sbashrc="source ~/.bashrc"
    alias vbashrc="vim ~/bin/code/working_knowledge/profiles/.bashrc"
    
    #alias ubashrc="xargs 1 | ~/bin/code/working_knowledge/profiles/update_profile.sh; sleep(1); sbashrc"

    # Settings
    alias python="python3"



# Terminal Colors:
#   RESOURCES:
#       - https://geoff.greer.fm/lscolors/
export CLICOLOR=1
export LSCOLORS=DxFxCxFxBxegedabagacad
export GREP_OPTIONS='--color=auto'



# PROMPTS:
#TIME: \[\e[31m\]\D{%c}\[\e[0m\]
#USER: [\[\e[1;43m\]\u\[\e[0m\]@\H]
PS1="\[\e[36m\]\w\n\[\e[0m\]$ "
