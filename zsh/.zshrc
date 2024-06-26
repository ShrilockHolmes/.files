export HISTCONTROL=erasedups:ignoredups:ignorespace
export FZF_COMPLETION_TRIGGER='<Ctrl-t>'
# Set the default editor
alias edit='nvim $(fzf)'
export EDITOR=nvim
alias vim='nvim'
alias pacman-mirrors='sudo reflector --sort rate --verbose -l 30 --save /etc/pacman.d/mirrorlist'
# To have colors for ls and all grep commands such as grep, egrep and zgrep
export CLICOLOR=1

# for corretions
setopt correct
# Alias's to modified commands
alias cp='cp -i'
alias mv='mv -i'
alias rm='trash -v'
alias mkdir='mkdir -p'
alias ping='ping -c 10'
alias cls='clear'
alias vi='nvim'

# Change directory aliases
alias home='cd ~'
alias ../='cd ../'


# Alias's for multiple directory listing commands
alias ls='ls -aFh --color=always' # add colors and file type extensions
alias ll='ls -Fls' # long listing format
alias ldir="ls -l | egrep '^d'" # directories only

# alias chmod commands
alias mx='chmod a+x'
# Alias's for archives
alias mktar='tar -cvf'
alias mkbz2='tar -cvjf'
alias mkgz='tar -cvzf'

# Extracts any archive(s) (if unp isn't installed)
extract () {
	for archive in "$@"; do
		if [ -f "$archive" ] ; then
			case $archive in
				*.tar.bz2)   tar xvjf $archive    ;;
				*.tar.gz)    tar xvzf $archive    ;;
				*.bz2)       bunzip2 $archive     ;;
				*.rar)       rar x $archive       ;;
				*.gz)        gunzip $archive      ;;
				*.tar)       tar xvf $archive     ;;
				*.tbz2)      tar xvjf $archive    ;;
				*.tgz)       tar xvzf $archive    ;;
				*.zip)       unzip $archive       ;;
				*.Z)         uncompress $archive  ;;
				*.7z)        7z x $archive        ;;
				*)           echo "don't know how to extract '$archive'..." ;;
			esac
		else
			echo "'$archive' is not a valid file!"
		fi
	done
}
export PATH=$PATH:"$HOME/.local/bin:$HOME/.cargo/bin:"

#eval "$(zoxide init zsh)"

eval "$(starship init zsh)"
source <(fzf --zsh)
# antigen zsh
source ~/antigen.zsh
antigen bundle zsh-users/zsh-syntax-highlighting
antigen bundle zsh-users/zsh-autosuggestions
antigen apply
