package main

// imports in golang
import (
	"fmt"
	"os"

	tea "github.com/charmbracelet/bubbletea"
)

// This defines my model, the state of my app
// My current state is count
// This holds all the data my app is to remember
// for example a bigger app would be
// typer model struct{
// 	count int
// 	textInput textinput.Model
// 	spinner spinner.Model
// 	loading bool
// }

type model struct {
	count int
}

// - Init runs once on startup
// - It can return a command

func (m model) Init() tea.Cmd {
	return nil
}

func (m model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch msg := msg.(type) {
	case tea.KeyMsg:
		switch msg.String() {
		case "q", "ctrl+c":
			return m, tea.Quit
		case "up":
			m.count++
		case "down":
			m.count--
		}
	}
	return m, nil
}

func (m model) View() string {
	return fmt.Sprintf("Count: %d\n\n up //down to change", m.count)
}

func main() {
	p := tea.NewProgram(model{})
	if err := p.Start(); err != nil {
		fmt.Println("Error in prog", err)
		os.Exit(1)
	}
}
