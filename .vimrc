"==================================================
" Basic Setting: Visual
"==================================================
set	background=dark		" Can only be set to one of two values: dark, light
set cmdheight=4					" Number of screen lines to use for the command-line
set	nocursorcolumn				" Highlights the column where the cursor is located
set	nocursorline				" Highlight the line where the cursor is
set guioptions+=m
set guioptions+=T
set guioptions+=l
set guioptions+=r
set guioptions+=b				"m: menu, T: toolbar, l,r,b: scrollbar
set guifont=Monospace\ Regular\ 13
set laststatus=2				" Set whether or not to display a status line in the last window
set lazyredraw					" The screen does not update when you are in the middle of an action (such as a macro)
set linebreak					" Lines are truncated on a word-by-word basis
set linespace=4					" Set the distance between rows, default is 0
set	number						" Shows the line number on the left side of the screen
set	numberwidth=4				" Sets the width of the line number on the left side of the screen. The default is 4
set	norelativenumber				" Show line numbers relative to cursor position
set	ruler						" Show cursor position information in the status line
set	showcmd						" In NORMAL mode, it shows the command you are typing in the lower right corner of the screen
set	showmatch					" Highlight matching parentheses. Defaults to off
set	showtabline=1				" 0: X, 1: default, 2: always
set showbreak=+++\ 				" w/ wrap
set	sidescroll=2				" w/ wrap
set	sidescrolloff=10			" w/ wrap
set	nowrap						" Represents long lines that go beyond the screen as multiple lines. Default is on.
set	listchars=					" reset
set	listchars+=extends:» 
set	listchars+=precedes:< 
set listchars+=tab:>-
set listchars+=trail:·			" Represent tabs as ` and spaces, and trailing blanks as 
set	nolist	
set	wildmenu					" Extend command-line autocomplete to make it more convenient
set	wildmode=list:full			" wildmenu display option
set	viewdir=~/.vim/view			" Directory for vim view file

augroup remember_folds
	autocmd!
	autocmd BufWinLeave *.* mkview
	autocmd BufWinEnter *.* silent! loadview
augroup END

"==================================================
" Basic Setting: Vim Env. & Editing
"==================================================
set loadplugins
filetype on						" Enable type file detection. Vim will be able to try to detect the type of file in use.
filetype plugin on				" Enable plugins and load plugin for the detected file type.
filetype indent on				" Load an indent file for the detected file type.
syntax on						" Turn syntax highlighting on.

set	tags=~/projects/tags

set autochdir					" Automatically change the working directory when opening files, moving buffers, etc
set	autoindent					" When you type Enter in INSERT mode to go down to the next line, it will automatically indent for you
set	autoread					" If the contents of a file change outside of VIM, it is automatically re-read
set	noautowrite					" Automatically saves files whenever you run certain commands with changes
set	backspace=indent,eol,start	" This option sets the delete function for the <BS> key
set	backup						" Create a backup before overwriting and saving the file
set	backupdir=~/.vim/backup		
set	cindent						" Automatically apply C-style indentation when editing
set	clipboard=unnamed			" Associating the unnamed register with the clipboard where all copy/delete operations are entered
set	nocompatible				" Sets the compatibility with the VI

"set	complete
set confirm						" Get confirmation from the user when using commands like :q, :bd, etc
set	noexpandtab					" When you press the tab key, you enter a set number of spaces, not tabs
set	tabstop=4					" Sets how many <Tab>s are replaced by <Space>s. The default is 0.
set	shiftwidth=4				" Specifies the indent length used by cindent, <<, >>. The default is 8
set	nogdefault					" Setting the g-flag to default when using the :substitute command, i.e. :s
set	hlsearch					" In the search results, highlight the string that matches the search term
set	history=50					" Remembers the history of the command by the specified number
set	ignorecase					" Ignore case when searching (you can search in lowercase as well as uppercase)
set	incsearch					" /search to perform a search for each letter entered
set	smartcase					" Don't ignore case if the search term contains capital letters
set	matchpairs+=<:>				" Specifies the pair of parentheses to move to %
set	mouse=a						" Set mouse usage by mode
set	nomousehide					" Hide the mouse pointer while typing
set	nrformats+=alpha			" <C-a>, <C-x> Specify a pattern of numbers to be incremented or decremented
set	smartindent					" When you edit the next line, it will automatically indent it to take into account the programming language syntax
set	smarttab					" When clearing space indents with <BS>, delete on a tab-by-tab basis
set	visualbell					" Notify you on screen when an error occurs without beeping


" for indent conflict during verilog coding
autocmd	FileType * setlocal comments-=://
set	formatoptions-=r
"==================================================
" Map Setting
"==================================================
map ,s			:w<CR> :so ~/.vimrc<CR> :noh<CR>
map ,v			:e	~/.vimrc<CR>
map ,b			:e  ~/.bash_aliases<CR>

map ,t			:!cd ~/projects;ctags -R<CR><CR>

map ,1			:e	~/.vim/pack/plugins/start/vim-snippets/snippets/verilog.snippets<CR>
map ,2			:e	~/.vim/pack/plugins/start/vim-snippets/snippets/_.snippets<CR>

map ,q			:q<CR>
map ,w			:w<CR>

map ga		:Tabularize /

map ,n			:noh<CR>

map <F2>		:NERDTreeToggle<CR>
map <F3>		:IndentGuidesToggle<CR>
map <F4>		:SyntasticToggleMode<CR>
map <F5>		:TagbarToggle<CR>
map <F8>		:w <CR> :!ivg	%:r:s?_tb??<CR><CR>
map <C-LEFT>	:tabprev<CR>
map <C-RIGHT>	:tabnext<CR>
map <C-n>		:tabnew<CR>

map <F10>		:w <CR> :!yosys -p "read_verilog %; hierarchy -check;" > ./log/%.yosys<CR> :!gvim ./log/%.yosys<CR>

map ,,i			:call verilog#VInst(0)<CR>
map ,,t			:call verilog#VInst(1)<CR>
map ,4			:e ~/.vim/pack/custom/start/vim-functions/autoload/functions.vim<CR>

map f*			:call cstFuncs#FontChange()<CR>
map f[			:call cstFuncs#FontSizeMod(-1)<CR>
map f]			:call cstFuncs#FontSizeMod(+1)<CR>
map s[			:call cstFuncs#LineSpace(-1)<CR>
map s]			:call cstFuncs#LineSpace(+1)<CR>
map c[			:call cstFuncs#CMDHeight(-1)<CR>
map c]			:call cstFuncs#CMDHeight(+1)<CR>

nmap \n			:call cstFuncs#ToggleRelativeNumber()<CR>
nmap \l			:call cstFuncs#ToggleCursorLine()<CR>
nmap \c			:call cstFuncs#ToggleListChars()<CR>
nmap \m			:call cstFuncs#ToggleGUIMenu()<CR>
nmap \w			:call cstFuncs#ToggleWrap()<CR>
"==================================================
" PlugIn Configurations
"==================================================
" gruvbox
set background=dark
let g:gruvbox_contrast_dark='hard' " hard or soft
let g:gruvbox_contrast_dark
set termguicolors
colorscheme gruvbox 
" nerdtree
let g:NERDTreeWinSize=20
" syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 0
let g:syntastic_check_on_open = 0
let g:syntastic_check_on_wq =  1
let g:syntastic_error_symbol = 'E'
let g:syntastic_warning_symbol = 'W'
let g:syntastic_loc_list_height = 4
let g:syntastic_verilog_checkers = ['iverilog']
let g:syntastic_python_checkers = ['python3']
let g:syntastic_cpp_compiler = 'g++'
let g:syntastic_cpp_compiler_options = '-std=c++14'
" snipMate
imap <C-J> <Plug>snipMateNextOrTrigger
