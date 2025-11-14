Public Class Form3
    Private Sub InsertNameButton_Click(sender As Object, e As EventArgs) Handles InsertNameButton.Click
        If InsertNameTextBox.Text.Trim() IsNot "" Then
            RegisterStudentListBox.Items.Add(InsertNameTextBox.Text)
        End If
    End Sub

    Private Sub SelectStudentButton_Click(sender As Object, e As EventArgs) Handles SelectStudentButton.Click
        If RegisterStudentListBox.SelectedItem IsNot Nothing Then
            Dim selected As String = RegisterStudentListBox.SelectedItem
            SelectedStudentListBox.Items.Add(selected)
        End If
    End Sub

    Private Sub SortButton_Click(sender As Object, e As EventArgs) Handles SortButton.Click
        SelectedStudentListBox.Sorted = True
    End Sub

    Private Sub RemoveButton_Click(sender As Object, e As EventArgs) Handles RemoveButton.Click
        SelectedStudentListBox.Items.Clear()
    End Sub
End Class