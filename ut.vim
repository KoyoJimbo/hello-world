"deinvimの設定
let g:cache_home = empty($XDG_CACHE_HOME) ? expand('$HOME/.cache') : $XDG_CACHE_HOME
let g:config_home = empty($XDG_CONFIG_HOME) ? expand('$HOME/.config') : $XDG_CONFIG_HOME

" dein {{{
let s:dein_cache_dir = g:cache_home . '/dein'

" reset augroup
augroup MyAutoCmd
    autocmd!
augroup END

if &runtimepath !~# '/dein.vim'
    let s:dein_repo_dir = s:dein_cache_dir . '/repos/github.com/Shougo/dein.vim'

    " Auto Download
    if !isdirectory(s:dein_repo_dir)
        call system('git clone https://github.com/Shougo/dein.vim ' . shellescape(s:dein_repo_dir))
    endif

    " dein.vim をプラグインとして読み込む
    execute 'set runtimepath^=' . s:dein_repo_dir
endif

" dein.vim settings
let g:dein#install_max_processes = 16
let g:dein#install_progress_type = 'title'
let g:dein#install_message_type = 'none'
let g:dein#enable_notification = 1

if dein#load_state(s:dein_cache_dir)
    call dein#begin(s:dein_cache_dir)

    let s:toml_dir = g:config_home . '/dein'

"
    call dein#load_toml(s:toml_dir . '/plugins.toml', {'lazy': 0})
    call dein#load_toml(s:toml_dir . '/lazy.toml', {'lazy': 1})
    if has('nvim')
        call dein#load_toml(s:toml_dir . '/neovim.toml', {'lazy': 1})
    endif
"
    call dein#end()
    call dein#save_state()
endif

if has('vim_starting') && dein#check_install()
    call dein#install()
endif
" }}}

"for indentLine plugin
let g:indentLine_color_term = 111
let g:indentLine_color_gui = '#708090'
let g:indentLine_char = '┆' "use ¦, ┆ or │ 

"setting
"文字コードをUFT-8に設定
set fenc=utf-8
" バックアップファイルを作らない
set nobackup
" スワップファイルを作らない
set noswapfile
" 編集中のファイルが変更されたら自動で読み直す
set autoread
" バッファが編集中でもその他のファイルを開けるように
set hidden
" 入力中のコマンドをステータスに表示する
set showcmd


" 見た目系
" 行番号を表示
set number
" 現在の行を強調表示
set cursorline
" 現在の行を強調表示（縦）
set cursorcolumn
" 行末の1文字先までカーソルを移動できるように
set virtualedit=onemore
" インデントはスマートインデント
set smartindent
" ビープ音を可視化
set visualbell
" 括弧入力時の対応する括弧を表示
set showmatch
"ノーマルモード時に「%」で対応するカッコにジャンプ出来ます。
source $VIMRUNTIME/macros/matchit.vim " Vimの「%」を拡張する
" ステータスラインを常に表示
set laststatus=2
" コマンドラインの補完
set wildmode=list:longest
"行末の空白文字のハイライト
augroup HighlightTrailingSpaces
  autocmd!
  autocmd VimEnter,WinEnter,ColorScheme * highlight TrailingSpaces term=underline guibg=Red ctermbg=Red
  autocmd VimEnter,WinEnter * match TrailingSpaces /\s\+$/
augroup END
" 折り返し時に表示行単位での移動できるようにする
nnoremap j gj
nnoremap k gk
"全角スペースの可視化
highlight ZenkakuSpace cterm=underline ctermfg=lightblue guibg=#666666
au BufNewFile,BufRead * match ZenkakuSpace /　/

"行頭のスペースの連続をハイライトさせる
"b文字も区別されずにハイライトされるので、区別したいときはTab文字の表示を別に
"設定する必要がある。
function! SOLSpaceHilight()
    syntax match SOLSpace "^\s\+" display containedin=ALL
    highlight SOLSpace term=underline ctermbg=LightGray
endf

" Tab系
" 不可視文字を可視化(タブが「▸-」と表示される)
""set list  listchars=tab:\▸\-

"Space 可視化
set list


""function! Whitespace()
""    if !exists('b:ws')
""        highlight Conceal ctermbg=NONE ctermfg=240 cterm=NONE guibg=NONE guifg=#585858 gui=NONE
""        highlight link Whitespace Conceal
""        let b:ws = 1
""    endif
""
""    syntax clear Whitespace
""    syntax match Whitespace / / containedin=ALL conceal cchar=·
""    setlocal conceallevel=2 concealcursor=c
""endfunction

""augroup Whitespace
""    autocmd!
""    autocmd BufEnter,WinEnter * call Whitespace()
""augroup END


""Tab文字を半角スペースにする
set expandtab
"tab 設定
:set noexpandtab
:set tabstop=4
:set shiftwidth=4
:set softtabstop=0
" 行頭以外のTab文字の表示幅（スペースいくつ分）
set tabstop=4
" 行頭でのTab文字の表示幅
set shiftwidth=4


" 検索系
" 検索文字列が小文字の場合は大文字小文字を区別なく検索する
set ignorecase
" 検索文字列に大文字が含まれている場合は区別して検索する
set smartcase
" 検索文字列入力時に順次対象文字列にヒットさせる
set incsearch
" 検索時に最後まで行ったら最初に戻る
set wrapscan
" 検索語をハイライト表示
set hlsearch
" ESC連打でハイライト解除
nmap <Esc><Esc> :nohlsearch<CR><Esc>


"カーソルの設定
" 挿入モードでのカーソル移動
inoremap <C-n> <Down>
inoremap <C-p> <Up>
inoremap <C-b> <Left>
inoremap <C-f> <Right>
"Ctrl+lで行末に；をつけます。
"Ctrl+sで行末に：をつけます。
inoremap <silent> <C-k> <Esc>$<Insert><Right>
inoremap <silent> <C-l> <Esc>$<Insert><Right> ;<Left><BS><Right>
inoremap <silent> <C-s> <Esc>$<Insert><Right> :<Left><BS><Right>
"Ctrl-e 	カーソルを行の末尾へ移動
"Ctrl-d 	カーソルの右の文字を削除
"Ctrl-h 	カーソルを左の文字を削除
imap <C-e> <End>
imap <C-d> <Del>
imap <C-h> <BS>
"nerdtree -> C-e
nnoremap <silent><C-t> :NERDTreeToggle<CR>


"閉じ括弧補完
inoremap { {}<Left>
inoremap{<Enter> {}<Left><CR><C-h><ESC><S-o>
inoremap ( ()<Left>
inoremap " ""<LEFT>
inoremap ' ''<LEFT>
inoremap [ []<LEFT>


""c言語専用
inoremap <A-k> #include<stdio.h><CR><ESC><S-o>int<Space>main(void){}<Left><CR><C-h>return<Space>0;<CR><Up><Space><Space><Space><Space><Left><Left><Left><Left><ESC><S-o>
inoremap <A-o> for()<Left>
inoremap <A-e> #define<Space>
inoremap <A-p> printf("");<Left><Left><Left>
inoremap <A-s> scanf("%",&);<Left><Left><Left><Left><Left>
inoremap <A-c> char<space>;<Left>
inoremap <A-i> int<space>;<Left>
inoremap <A-d> double<space>;<Left>
inoremap <A-w> while()<Left>
inoremap <A-r> return<space>;<Left>


"
"
"jjでインサートモードからコマンドモードに戻れる
inoremap <silent> jj <ESC>
inoremap <silent> <A-f> <Right>
set wildmenu " コマンドモードの補完
set history=5000 " 保存するコマンド履歴の数
"クリップボードからペーストする時だけインデントしないようにしてくれます。
if &term =~ "xterm"
    let &t_SI .= "\e[?2004h"
    let &t_EI .= "\e[?2004l"
    let &pastetoggle = "\e[201~"

    function XTermPasteBegin(ret)
        set paste
        return a:ret
    endfunction

    inoremap <special> <expr> <Esc>[200~ XTermPasteBegin("")
endif

"python3適用
let g:python3_host_prog = $PYENV_ROOT . '/shims/python3'

"画面分割
nnoremap s <Nop>
nnoremap sj <C-w>j
nnoremap sk <C-w>k
nnoremap sl <C-w>l
nnoremap sh <C-w>h
nnoremap sJ <C-w>J
nnoremap sK <C-w>K
nnoremap sL <C-w>L
nnoremap sH <C-w>H
nnoremap sn gt
nnoremap sp gT
nnoremap sr <C-w>r
nnoremap s= <C-w>=
nnoremap sw <C-w>w
nnoremap so <C-w>_<C-w>|
nnoremap sO <C-w>=
nnoremap sN :<C-u>bn<CR>
nnoremap sP :<C-u>bp<CR>
nnoremap st :<C-u>tabnew<CR>
nnoremap sT :<C-u>Unite tab<CR>
nnoremap ss :<C-u>sp<CR>
nnoremap sv :<C-u>vs<CR>
nnoremap sq :<C-u>q<CR>
nnoremap sQ :<C-u>bd<CR>
nnoremap sb :<C-u>Unite buffer_tab -buffer-name=file<CR>
nnoremap sB :<C-u>Unite buffer -buffer-name=file<CR>
"ウィンドウ分割
""水平分割 	:split 	ss
""垂直分割 	:vsplit 	sv
"ウィンドウ間移動
""左に移動 	<C-w>h 	sh
""下に移動 	<C-w>j 	sj
""上に移動 	<C-w>k 	sk
""右に移動 	<C-w>l 	sl
""次に移動 	<C-w>w 	sw
"ウィンドウ移動
""左に移動 	<C-w>H 	sH
""下に移動 	<C-w>J 	sJ
""上に移動 	<C-w>K 	sK
""右に移動 	<C-w>L 	sL
""回転 	<C-w>r 	sr
"カレントウィンドウのサイズ
""縦に最大化 	<C-w>_ 	なし
""横に最大化 	<C-w>パイプ 	なし
""縦横最大化 	なし 	so
""大きさを揃える 	<C-w>= 	sO もしくは s=
"タブ
""新規タブ 	:tabnew 	st
""次のタブに切替 	gt 	sn
""前のタブに切替 	gT 	sp
"閉じる
""ウィンドウを閉じる 	:q 	sq
""バッファを閉じる 	:bd 	sQ


"gvimrc
" カラースキームsierra好き
""colorscheme sierra
""colorscheme Alduin
colorscheme molokai
"
"背景色
set background=dark
""set background=light
syntax on
" 256色¬
set t_Co=256
""truecolor
set termguicolors



