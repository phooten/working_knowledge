# soucre ~/.bashrc to update changes



# ALIAS
    # Navigation:
    alias me="cd ~/"
    alias mecode="cd ~/bin/code"
    alias meprofiles="cd ~/bin/code/working_knowledge/profiles; echo \"Run './update_profile.sh', then 'sbash' to update changes.\""

    # Utility:
    alias ls="ls --color=auto"
    alias la="ls -lra"
    alias ll="ls -ltra"
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
#DEFUALT: PS1="\[\e[36m\]\w\n\[\e[0m\]$ "
# Bold Yellow: 	1;93 
# Bold Cyan: 	1;36
export PS1="\[\033[1;36m\]\u@\H: \w\n\[\033[1;36m\]\t Line:\#$ \[\033[0;37m\]"



