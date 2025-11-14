Public Class Form1
    Private Sub btnAdd_Click(sender As Object, e As EventArgs) Handles btnAdd.Click
        Dim score As Integer

        If txtID.Text.Trim() <> "" AndAlso txtName.Text.Trim() <> "" AndAlso Integer.TryParse(txtScore.Text, score) Then
            dgvStudents.Rows.Add(txtID.Text, txtName.Text, score)
            txtID.Clear()
            txtName.Clear()
            txtScore.Clear()
            HighlightFailRows()
        Else
            MessageBox.Show("Please enter valid data (Score must be a number).")
        End If
    End Sub

    Private Sub btnAverage_Click(sender As Object, e As EventArgs) Handles btnAverage.Click
        Dim total As Integer = 0
        Dim count As Integer = 0

        For Each row As DataGridViewRow In dgvStudents.Rows
            If row.IsNewRow Then Continue For
            Dim value = row.Cells("Score").Value
            If value IsNot Nothing AndAlso Integer.TryParse(value.ToString(), 0) Then
                total += CInt(value)
                count += 1
            End If
        Next

        If count > 0 Then
            lblAverage.Text = "Average Score: " & (total / count).ToString("F2")
        Else
            lblAverage.Text = "Average Score: N/A"
        End If
    End Sub

    Private Sub dgvStudents_CellValueChanged(sender As Object, e As DataGridViewCellEventArgs) Handles dgvStudents.CellValueChanged
        HighlightFailRows()
    End Sub

    Private Sub dgvStudents_RowsAdded(sender As Object, e As DataGridViewRowsAddedEventArgs) Handles dgvStudents.RowsAdded
        HighlightFailRows()
    End Sub

    Private Sub dgvStudents_RowsRemoved(sender As Object, e As DataGridViewRowsRemovedEventArgs) Handles dgvStudents.RowsRemoved
        HighlightFailRows()
    End Sub

    Private Sub HighlightFailRows()
        For Each row As DataGridViewRow In dgvStudents.Rows
            If row.IsNewRow Then Continue For
            Dim value = row.Cells("Score").Value
            If value IsNot Nothing AndAlso Integer.TryParse(value.ToString(), 0) Then
                Dim score As Integer = CInt(value)
                If score < 50 Then
                    row.DefaultCellStyle.BackColor = Color.LightPink
                Else
                    row.DefaultCellStyle.BackColor = Color.White
                End If
            End If
        Next
    End Sub
End Class
