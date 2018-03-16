<TextInputColumn
  onChange={this.handleUsernameChange}
  onSubmitEditing={() => this.passwordInput.focus()}
/>
<TextInputColumn
  setRef={(element) => { this.passwordInput = element; }}
/>
